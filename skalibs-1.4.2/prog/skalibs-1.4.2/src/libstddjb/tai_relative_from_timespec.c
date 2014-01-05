/* ISC license. */

#include <sys/types.h>
#include <time.h>
#include "tai.h"

int tai_relative_from_timespec (struct tai *t, struct timespec const *ts)
{
  tai_u64(t, ts->tv_sec) ;
  return 1 ;
}
