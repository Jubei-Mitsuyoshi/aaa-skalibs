/* ISC license. */

#include "fmtscan.h"
#include "stralloc.h"
#include "netstring.h"

int netstring_encode (stralloc *sa, char const *s, unsigned int len)
{
  char fmt[UINT_FMT] ;
  unsigned int pos = uint_fmt(fmt, len) ;
  if (!stralloc_readyplus(sa, pos + len + 2)) return 0 ;
  stralloc_catb(sa, fmt, pos) ;
  stralloc_catb(sa, ":", 1) ;
  stralloc_catb(sa, s, len) ;
  stralloc_catb(sa, ",", 1) ;
  return 1 ;
}
