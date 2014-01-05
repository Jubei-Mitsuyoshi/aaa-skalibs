/* ISC license. */

#include "uint32.h"
#include "sredfa.h"
#include "sredfa-internal.h"

int sredfa_feedn (sredfa_ref p, uint32 *u, char const *s, unsigned int n)
{
  if (*u == SREDFA_START) p->word.len = 0 ;
  if (!stralloc_catb(&p->word, s, n)) return 0 ;
  switch (sredfa_matchword(p))
  {
    case 0: *u = SREDFA_DUMMY ; break ;
    case 1: *u = SREDFA_DUMMY | SREDFA_ACCEPT ; break ;
    default : *u = SREDFA_DUMMY | SREDFA_ERROR ; return 0 ;
  }
  return 1 ;
}
