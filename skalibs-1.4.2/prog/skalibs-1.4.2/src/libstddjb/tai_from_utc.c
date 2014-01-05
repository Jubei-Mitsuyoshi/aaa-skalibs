/* ISC license. */

#include "uint64.h"
#include "tai.h"
#include "djbtime.h"

int tai_from_utc (struct tai *t, uint64 u)
{
  if (leapsecs_add(&u, 0) < 0) return 0 ;
  u += 10 ;
  t->x = u ;
  return 1 ;
}
