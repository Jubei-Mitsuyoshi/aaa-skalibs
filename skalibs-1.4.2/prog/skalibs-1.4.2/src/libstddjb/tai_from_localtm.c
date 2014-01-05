/* ISC license. */

#include <sys/types.h>
#include <time.h>
#include "uint64.h"
#include "tai.h"
#include "djbtime.h"

int tai_from_localtm (struct tai *t, struct tm const *l)
{
  uint64 u ;
  if (!ltm64_from_localtm(&u, l)) return 0 ;
  return tai_from_ltm64(t, u) ;
}
