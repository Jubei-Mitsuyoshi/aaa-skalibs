/* ISC license. */

#include "uint64.h"
#include "tai.h"

int taia_to_millisecs (struct taia const *a)
{
  if (a->sec.x > (uint64)2147483) return -1 ;
  if ((a->sec.x == (uint64)2147483) && (a->nano > 647000000U)) return -1 ;
  return a->sec.x * 1000 + a->nano / 1000000U ;
}
