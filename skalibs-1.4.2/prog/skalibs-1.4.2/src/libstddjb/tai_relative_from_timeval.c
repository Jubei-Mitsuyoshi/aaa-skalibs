/* ISC license. */

#include <sys/time.h>
#include "tai.h"

int tai_relative_from_timeval (struct tai *t, struct timeval const *tv)
{
  tai_u64(t, tv->tv_sec) ;
  return 1 ;
}
