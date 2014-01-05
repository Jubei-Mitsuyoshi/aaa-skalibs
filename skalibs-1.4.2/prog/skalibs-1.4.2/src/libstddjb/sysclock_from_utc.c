/* ISC license. */

#include "skalibs-config.h"
#include "uint64.h"
#include "djbtime.h"

#ifdef SKALIBS_FLAG_CLOCKISTAI

#include "tai.h"

int sysclock_from_utc (uint64 *u)
{
  struct tai t ;
  if (!tai_from_utc(&t, *u)) return 0 ;
  *u = t.x - 10 ;
  return 1 ;
}

#else

int sysclock_from_utc (uint64 *u)
{
  (void)u ;
  return 1 ;
}

#endif
