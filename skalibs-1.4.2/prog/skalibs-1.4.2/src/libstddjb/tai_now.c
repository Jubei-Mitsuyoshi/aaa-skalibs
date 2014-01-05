/* ISC license. */

/* MT-unsafe */

#include <time.h>
#include "uint64.h"
#include "tai.h"

int tai_now (struct tai *t)
{
  register uint64 u = TAI_MAGIC + time(0) ;
  return tai_from_sysclock(t, u) ;
}
