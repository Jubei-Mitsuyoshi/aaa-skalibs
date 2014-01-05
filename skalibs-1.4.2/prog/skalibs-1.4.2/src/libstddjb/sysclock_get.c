/* ISC license. */

#include "skalibs-config.h"
#include "sysdeps.h"
#include "tai.h"

#ifdef SKALIBS_FLAG_USERT
# ifndef HASCLOCKRT
#  undef SKALIBS_FLAG_USERT
#  warning "flag-usert set but HASCLOCKRT not found. Clearing flag-usert."
# endif
#endif

#ifndef SKALIBS_FLAG_USERT
# ifndef HASGETTIMEOFDAY
#  error "flag-usert clear but HASGETTIMEOFDAY not found. Does your system have a working clock?"
# endif
#endif


#ifdef SKALIBS_FLAG_USERT

#include <time.h>

int sysclock_get (struct taia *a)
{
  struct taia aa ;
  struct timespec now ;
  if (clock_gettime(CLOCK_REALTIME, &now) < 0) return 0 ;
  if (!taia_from_timespec(&aa, &now)) return 0 ;
  taia_add(a, &aa, &taia_nano500) ;
  return 1 ;
}

#else

#include <sys/time.h>

int sysclock_get (struct taia *a)
{
  struct taia aa ;
  struct timeval now ;
  if (gettimeofday(&now, 0) < 0) return 0 ;
  if (!taia_from_timeval(&aa, &now)) return 0 ;
  taia_add(a, &aa, &taia_nano500) ;
  return 1 ;
}

#endif
