/* ISC license. */

#include <sys/types.h>
#include <errno.h>
#include <time.h>
#include "tai.h"
#include "uint64.h"
#include "djbtime.h"

int ltm64_from_localtm (uint64 *uu, struct tm const *l)
{
  struct tm ll = *l ;
  time_t u = mktime(&ll) ;
  if (u == (time_t)-1) return (errno = EINVAL, 0) ;
  *uu = TAI_MAGIC + u ;
  return 1 ;
}
