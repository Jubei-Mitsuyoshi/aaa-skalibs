/* ISC license. */

#include <sys/types.h>
#include <time.h>
#include "uint64.h"
#include "djbtime.h"

int utc_from_localtm (uint64 *uu, struct tm const *l)
{
  uint64 u ;
  if (!ltm64_from_localtm(&u, l)) return 0 ;
  if (!utc_from_ltm64(&u)) return 0 ;
  *uu = u ;
  return 1 ;
}
