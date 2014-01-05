/* ISC license. */

#include "uint64.h"
#include "tai.h"
#include "djbtime.h"

int taia_from_ntp (struct taia *a, uint64 u)
{
  struct tai secs = { u >> 32 } ;
  uint64 frac ;
  if (secs.x <= 0x7FFFFFFFUL) secs.x |= ((uint64)1 << 32) ;
  secs.x += TAI_MAGIC ;
  secs.x -= NTP_OFFSET ;
  if (!tai_from_utc(&secs, secs.x)) return 0 ;
  frac = (u & 0xFFFFFFFFUL) * NTP_MAGIC_FRAC ;
  a->sec = secs ;
  a->nano = frac / 1000000000U ;
  if (a->nano >= 999999999U) a->nano = 999999999U ;
  a->atto = frac % 1000000000U ;
  return 1 ;
}
