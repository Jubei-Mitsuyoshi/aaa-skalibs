/* ISC license. */

/* MT-unsafe */

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
# ifndef HASSETTIMEOFDAY
#  error "flag-usert clear but HASSETTIMEOFDAY not found. How do your set your system clock?"
# endif
#endif


#ifdef SKALIBS_FLAG_USERT

#include <time.h>

int sysclock_set (struct taia const *a)
{
  struct timespec now ;
  struct taia aa ;
  taia_add(&aa, a, &taia_nano500) ;
  if (!timespec_from_taia(&now, &aa)) return 0 ;
  if (clock_settime(CLOCK_REALTIME, &now) < 0) return 0 ;
  return 1 ;
}

#else

#include <sys/time.h>

int sysclock_set (struct taia const *a)
{
  struct timeval now ;
  struct taia aa ;
  taia_add(&aa, a, &taia_nano500) ;
  if (!timeval_from_taia(&now, &aa)) return 0 ;
  if (settimeofday(&now, 0) < 0) return 0 ;
  return 1 ;
}

#endif
