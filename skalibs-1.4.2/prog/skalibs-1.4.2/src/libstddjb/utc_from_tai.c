/* ISC license. */

#include "uint64.h"
#include "tai.h"
#include "djbtime.h"

int utc_from_tai (uint64 *u, struct tai const *t)
{
  uint64 tt = t->x - 10 ;
  if (leapsecs_sub(&tt) < 0) return 0 ;
  *u = tt ;
  return 1 ;
}
