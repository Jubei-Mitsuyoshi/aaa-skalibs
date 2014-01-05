/* ISC license. */

#include "uint.h"
#include "bytestr.h"
#include "stralloc.h"
#include "netstring.h"

int netstring_appendb (stralloc *sa, char const *s, unsigned int len)
{
  char fmt[UINT_FMT] ;
  unsigned int n = uint_fmt(fmt, len) ;
  if (!stralloc_readyplus(sa, len + n + 2)) return 0 ;
  fmt[n] = ':' ;
  byte_copy(sa->s + sa->len, n+1, fmt) ;
  byte_copy(sa->s + sa->len + n+1, len, s) ;
  sa->s[sa->len + n+1 + len] = ',' ;
  sa->len += n + 2 + len ;
  return 1 ;
}
