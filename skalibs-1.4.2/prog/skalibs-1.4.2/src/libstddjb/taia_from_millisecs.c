/* ISC license. */

#include <errno.h>
#include "tai.h"

int taia_from_millisecs (struct taia *a, int millisecs)
{
  if (millisecs < 0) return (errno = EINVAL, 0) ;
  a->sec.x = millisecs / 1000 ;
  a->nano = (millisecs % 1000) * 1000000U ;
  a->atto = 0 ;
  return 1 ;
}
