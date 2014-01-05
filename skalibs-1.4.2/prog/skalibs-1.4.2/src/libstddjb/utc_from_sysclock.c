/* ISC license. */

#include "skalibs-config.h"
#include "uint64.h"
#include "djbtime.h"

#ifdef SKALIBS_FLAG_CLOCKISTAI

#include "tai.h"

int utc_from_sysclock (uint64 *u)
{
  struct tai t = { .x = *u + 10U } ;
  return utc_from_tai(u, &t) ;
}

#else

int utc_from_sysclock (uint64 *u)
{
  (void)u ;
  return 1 ;
}

#endif
