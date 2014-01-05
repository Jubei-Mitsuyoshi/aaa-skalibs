/* ISC license. */

#include "skalibs-config.h"
#include "uint64.h"
#include "djbtime.h"

#ifdef SKALIBS_FLAG_TZISRIGHT

int ltm64_from_utc (uint64 *u)
{
  return (leapsecs_add(u, 0) >= 0) ;
}

#else

int ltm64_from_utc (uint64 *u)
{
  (void)u ;
  return 1 ;
}

#endif
