/* ISC license. */

#include <sys/types.h>
#include <time.h>
#include "tai.h"

int timespec_from_tai (struct timespec *ts, struct tai const *t)
{
  struct tai trel ;
  tai_u64(&trel, tai_sec(t) - TAI_MAGIC) ;
  return timespec_from_tai_relative(ts, &trel) ;
}
