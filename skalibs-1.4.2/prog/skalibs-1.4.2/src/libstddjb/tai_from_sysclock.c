/* ISC license. */

#include "skalibs-config.h"
#include "tai.h"

#ifdef SKALIBS_FLAG_CLOCKISTAI

int tai_from_sysclock (struct tai *t, uint64 u)
{
  tai_u64(t, u + 10U) ;
  return 1 ;
}

#else

#include "djbtime.h"

int tai_from_sysclock (struct tai *t, uint64 u)
{
  return tai_from_utc(t, u) ;
}

#endif
