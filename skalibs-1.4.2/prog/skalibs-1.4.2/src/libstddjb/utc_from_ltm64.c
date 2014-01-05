/* ISC license. */

#include "skalibs-config.h"
#include "uint64.h"
#include "djbtime.h"

#ifdef SKALIBS_FLAG_CLOCKISTAI

int utc_from_ltm64 (uint64 *u)
{
  return (leapsecs_sub(u) > 0) ;
}

#else

int utc_from_ltm64 (uint64 *u)
{
  (void)u ;
  return 1 ;
}

#endif
