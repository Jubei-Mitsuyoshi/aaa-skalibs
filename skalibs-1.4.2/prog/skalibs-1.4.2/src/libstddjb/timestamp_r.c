/* ISC license. */

#include "tai.h"

int timestamp_r (char *s, struct taia *stamp)
{
  if (!taia_sysclock(stamp)) return 0 ;
  timestamp_fmt(s, stamp) ;
  return 1 ;
}
