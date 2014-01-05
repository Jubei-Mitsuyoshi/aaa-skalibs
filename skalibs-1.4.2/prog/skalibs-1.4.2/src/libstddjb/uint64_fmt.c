/* ISC license. */

#include "uint64.h"
#include "fmtscan.h"

unsigned int uint64_fmt_base (char *s, uint64 x, unsigned char base)
{
  register unsigned int len = 1 ;
  {
    register uint64 q = x ;
    while (q >= base) { len++ ; q /= base ; }
  }
  if (s)
  {
    s += len ;
    do { *--s = fmtscan_asc(x % base) ; x /= base ; } while (x) ;
  }
  return len ;
}
