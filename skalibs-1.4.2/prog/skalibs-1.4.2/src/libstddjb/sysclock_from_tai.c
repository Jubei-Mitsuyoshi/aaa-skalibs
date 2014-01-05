/* ISC license. */

#include "skalibs-config.h"
#include "tai.h"

#ifdef SKALIBS_FLAG_CLOCKISTAI

int sysclock_from_tai (uint64 *u, struct tai const *t)
{
  *u = t->x - 10U ;
  return 1 ;
}

#else

#include "djbtime.h"

int sysclock_from_tai (uint64 *u, struct tai const *t)
{
  return utc_from_tai(u, t) ;
}

#endif
