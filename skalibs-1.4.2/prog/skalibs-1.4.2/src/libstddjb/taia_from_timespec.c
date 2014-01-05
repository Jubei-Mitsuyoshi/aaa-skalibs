/* ISC license. */

#include <sys/types.h>
#include <time.h>
#include <errno.h>
#include "tai.h"

int taia_from_timespec (struct taia *a, struct timespec const *ts)
{
  if (!tai_from_timespec(taia_secp(a), ts)) return 0 ;
  a->nano = ts->tv_nsec ;
  a->atto = 0 ;
  return 1 ;
}
