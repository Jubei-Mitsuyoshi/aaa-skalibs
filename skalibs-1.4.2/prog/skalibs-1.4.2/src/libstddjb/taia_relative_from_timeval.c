/* ISC license. */

#include <sys/time.h>
#include <errno.h>
#include "tai.h"

int taia_relative_from_timeval (struct taia *a, struct timeval const *tv)
{
  if (!tai_relative_from_timeval(taia_secp(a), tv)) return 0 ;
  a->nano = 1000 * tv->tv_usec ;
  a->atto = 0 ;
  return 1 ;
}
