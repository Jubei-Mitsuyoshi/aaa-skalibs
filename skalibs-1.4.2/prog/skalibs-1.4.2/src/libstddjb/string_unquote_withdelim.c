/* ISC license. */

#include <errno.h>
#include "error.h"
#include "bytestr.h"
#include "fmtscan.h"
#include "skamisc.h"

#define PUSH0 0x40
#define PUSH  0x20
#define PUSHSPEC 0x10
#define STORE 0x08
#define CALC 0x04
#define SYNTAXERROR 0x02
#define BROKENPIPE 0x01

int string_unquote_withdelim (char *d, unsigned int *w, char const *s, unsigned int len, unsigned int *r, char const *delim, unsigned int delimlen)
{
  register unsigned int i = 0 ;
  static unsigned char const actions[5][9] =
  {
    { 0, 0, PUSH, PUSH, PUSH, PUSH, PUSH, PUSH, 0 },
    { PUSH, PUSH, 0, PUSH, PUSHSPEC, PUSH, PUSHSPEC, PUSH, BROKENPIPE },
    { PUSH0, PUSH0, PUSH0|PUSH, 0, PUSH0|PUSH, PUSH0|PUSH, PUSH0|PUSH, PUSH0|PUSH, PUSH0 },
    { SYNTAXERROR, SYNTAXERROR, STORE, SYNTAXERROR, STORE, STORE, SYNTAXERROR, SYNTAXERROR, BROKENPIPE },
    { SYNTAXERROR, SYNTAXERROR, CALC, SYNTAXERROR, CALC, CALC, SYNTAXERROR, SYNTAXERROR, BROKENPIPE }
  } ;
  static unsigned char const states[5][9] =
  {
    { 1, 5, 0, 0, 0, 0, 0, 0, 5 },
    { 0, 0, 2, 0, 0, 0, 0, 0, 6 },
    { 1, 5, 0, 3, 0, 0, 0, 0, 5 },
    { 6, 6, 4, 6, 4, 4, 6, 6, 6 },
    { 6, 6, 0, 6, 0, 0, 6, 6, 6 }
  } ;
  unsigned char class[256] = "7777777777777777777777777777777777777777777777772555555555777777777777777777777777777777777707777445554777777767776767673777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777" ;
  unsigned char store = 0 ;
  unsigned char state = 0 ;
  for (; i < delimlen ; i++)
    if (class[(unsigned char)delim[i]] == '7')
      class[(unsigned char)delim[i]] = '1' ;
    else return (errno = EINVAL, 0) ;
  *w = 0 ;

  for (i = 0 ; state < 5 ; i++)
  {
    unsigned char c = i < len ? class[(unsigned char)s[i]] - '0' : 8 ;
    unsigned char action = actions[state][c] ;
    state = states[state][c] ;
    if (action & PUSH0) d[(*w)++] = 0 ;
    if (action & PUSH) d[(*w)++] = s[i] ;
    if (action & PUSHSPEC) d[(*w)++] = 7 + byte_chr("abtnvfr", 7, s[i]) ;
    if (action & STORE) store = fmtscan_num(s[i], 16) << 4 ;
    if (action & CALC) d[(*w)++] = store | fmtscan_num(s[i], 16) ;
    if (action & SYNTAXERROR) errno = EPROTO ;
    if (action & BROKENPIPE) errno = EPIPE ;
  }
  *r = i - 1 ;
  return (state == 5) ;
}
