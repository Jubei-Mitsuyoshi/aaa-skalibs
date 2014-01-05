/* ISC license. */

#include <sys/time.h>
#include "tai.h"

int timeval_from_tai (struct timeval *tv, struct tai const *t)
{
  struct tai trel ;
  tai_u64(&trel, tai_sec(t) - TAI_MAGIC) ;
  return timeval_from_tai_relative(tv, &trel) ;
}
