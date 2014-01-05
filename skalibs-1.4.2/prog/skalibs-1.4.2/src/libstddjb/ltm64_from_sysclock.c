/* ISC license. */

#include "skalibs-config.h"
#include "uint64.h"
#include "djbtime.h"

#ifdef SKALIBS_FLAG_CLOCKISTAI

#include "tai.h"

int ltm64_from_sysclock (uint64 *u)
{
  struct tai t = { *u + 10U } ;
  return ltm64_from_tai(u, &t) ;
}

#else

int ltm64_from_sysclock (uint64 *u)
{
  return ltm64_from_utc(u) ;
}

#endif
