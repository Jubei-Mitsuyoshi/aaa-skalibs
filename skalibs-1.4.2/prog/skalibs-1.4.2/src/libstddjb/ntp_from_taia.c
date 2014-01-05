/* ISC license. */

#include <errno.h>
#include "uint64.h"
#include "tai.h"
#include "djbtime.h"

int ntp_from_taia (uint64 *u, struct taia const *a)
{
  uint64 secs, frac ;
  if (!utc_from_tai(&secs, taia_secp(a))) return 0 ;
  secs += NTP_OFFSET ;
  if (secs < TAI_MAGIC + 2147483648UL) goto ifail ;
  secs -= TAI_MAGIC ;
  if (secs >= ((uint64)3 << 31)) goto ifail ;
  secs &= (secs < ((uint64)1 << 32)) ? 0xFFFFFFFFUL : 0x7FFFFFFFUL ;
  frac = ((uint64)a->nano * 1000000000 + a->atto) / NTP_MAGIC_FRAC ;
  *u = (secs << 32) + (frac >> 32) ;
  return 1 ;
 ifail:
  errno = EINVAL ;
  return 0 ;
}
