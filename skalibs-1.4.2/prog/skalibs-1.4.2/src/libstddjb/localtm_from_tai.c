/* ISC license. */

#include <sys/types.h>
#include <time.h>
#include "uint64.h"
#include "tai.h"
#include "djbtime.h"

int localtm_from_tai (struct tm *l, struct tai const *t, int tz)
{
  uint64 u ;
  if (!ltm64_from_tai(&u, t)) return 0 ;
  return localtm_from_ltm64(l, u, tz) ;
}
