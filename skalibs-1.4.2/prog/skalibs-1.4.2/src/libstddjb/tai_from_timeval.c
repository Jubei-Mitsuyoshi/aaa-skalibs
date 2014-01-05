/* ISC license. */

#include <sys/time.h>
#include "tai.h"

int tai_from_timeval (struct tai *t, struct timeval const *tv)
{
  tai_unix(t, tv->tv_sec) ;
  return 1 ;
}
