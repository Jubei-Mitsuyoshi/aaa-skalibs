/* ISC license. */

#include "skalibs-config.h"
#include "uint64.h"
#include "tai.h"
#include "djbtime.h"

#ifdef SKALIBS_FLAG_TZISRIGHT

int ltm64_from_tai (uint64 *u, struct tai const *t)
{
  *u = t->x - 10U ;
  return 1 ;
}

#else

int ltm64_from_tai (uint64 *u, struct tai const *t)
{
  return utc_from_tai(u, t) ;
}

#endif
