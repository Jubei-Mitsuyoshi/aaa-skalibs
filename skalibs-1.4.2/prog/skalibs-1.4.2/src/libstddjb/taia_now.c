/* ISC license. */

/* MT-unsafe */

#include "skalibs-config.h"
#include "sysdeps.h"
#include "tai.h"

#ifdef SKALIBS_FLAG_USEMON
# ifndef HASCLOCKMON
#  undef SKALIBS_FLAG_USEMON
#  warning "flag-usemon set but HASCLOCKMON not found. Clearing flag-usemon."
# endif
#endif


#ifdef SKALIBS_FLAG_USEMON

static struct taia offset ;

int taia_init ()
{
  return taia_clockmon_init(&offset) ;
}

int taia_now (struct taia *a)
{
  static int initted = 0 ;
  if (!initted)
  {
    if (!taia_clockmon_init(&offset)) return 0 ;
    initted = 1 ;
  }
  return taia_clockmon(a, &offset) ;
}

#else

int taia_init ()
{
  return 1 ;
}

int taia_now (struct taia *a)
{
  return taia_sysclock(a) ;
}

#endif
