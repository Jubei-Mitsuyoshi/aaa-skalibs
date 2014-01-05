/* ISC license. */

#include <sys/types.h>
#include <time.h>
#include <errno.h>
#include "tai.h"

int timespec_from_taia_relative (struct timespec *ts, struct taia const *a)
{
  struct timespec tmp ;
  if (!timespec_from_tai_relative(&tmp, taia_secp(a)))
    return (errno = EINVAL, 0) ;
  ts->tv_sec = tmp.tv_sec ;
  ts->tv_nsec = a->nano ;
  return 1 ;
}
