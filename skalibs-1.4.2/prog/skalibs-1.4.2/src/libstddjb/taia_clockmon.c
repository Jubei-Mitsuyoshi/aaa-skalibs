/* ISC license. */

#include "sysdeps.h"
#include "tai.h"

#ifdef HASCLOCKMON

#include <time.h>

int taia_clockmon_init (struct taia *offset)
{
  struct taia a, b ;
  struct timespec ts ;
  if (!taia_sysclock(&a)) return 0 ;
  if (clock_gettime(CLOCK_MONOTONIC, &ts) < 0) return 0 ;
  if (!taia_from_timespec(&b, &ts)) return 0 ;
  taia_add(&a, &a, &taia_nano500) ;
  taia_sub(offset, &a, &b) ;
  return 1 ;
}

int taia_clockmon (struct taia *a, struct taia const *offset)
{
  struct timespec ts ;
  if (clock_gettime(CLOCK_MONOTONIC, &ts) < 0) return 0 ;
  if (!taia_from_timespec(a, &ts)) return 0 ;
  taia_add(a, a, offset) ;
  return 1 ;
}

#else

#include <errno.h>

int taia_clockmon_init (struct taia *offset)
{
  (void)offset ;
  return (errno = ENOSYS, 0) ;
}

int taia_clockmon (struct taia *a, struct taia const *offset)
{
  (void)a ; (void)offset ;
  return (errno = ENOSYS, 0) ;
}

#endif
