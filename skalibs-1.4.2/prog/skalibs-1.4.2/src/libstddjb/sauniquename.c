/* ISC license. */

#include <unistd.h>
#include "fmtscan.h"
#include "tai.h"
#include "stralloc.h"
#include "djbunix.h"
#include "skamisc.h"

int sauniquename (stralloc *sa)
{
  unsigned int base = sa->len ;
  int wasnull = !sa->s ;

  if (!stralloc_readyplus(sa, TIMESTAMP + UINT_FMT + 131)) return -1 ;
  sa->s[base] = ':' ;
  timestamp(sa->s + base + 1) ;
  sa->s[base + 1 + TIMESTAMP] = ':' ;
  sa->len = base + 2 + TIMESTAMP ;
  sa->len += uint_fmt(sa->s + sa->len, getpid()) ;
  sa->s[sa->len++] = ':' ;
  if (sagethostname(sa) == -1) goto err ;
  return 0 ;

err:
  if (wasnull) stralloc_free(sa) ; else sa->len = base ;
  return -1 ;
}
