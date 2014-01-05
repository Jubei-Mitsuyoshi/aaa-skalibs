/* ISC license. */

#include <sys/types.h>
#include <time.h>
#include "tai.h"

int tai_from_timespec (struct tai *t, struct timespec const *ts)
{
  tai_unix(t, ts->tv_sec) ;
  return 1 ;
}
