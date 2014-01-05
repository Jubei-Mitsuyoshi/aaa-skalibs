/* ISC license. */

#include <sys/types.h>
#include <time.h>
#include "uint64.h"
#include "djbtime.h"

int localtm_from_utc (struct tm *l, uint64 u, int tz)
{
  if (!ltm64_from_utc(&u)) return 0 ;
  return localtm_from_ltm64(l, u, tz) ;
}
