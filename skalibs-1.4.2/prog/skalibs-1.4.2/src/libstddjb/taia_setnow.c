/* ISC license. */

/* MT-unsafe */

#include "tai.h"

int taia_setnow (struct taia const *a)
{
  struct taia aa ;
  if (!sysclock_from_tai(&aa.sec.x, &a->sec)) return 0 ;
  aa.nano = a->nano ; aa.atto = a->atto ;
  return sysclock_set(&aa) ;
}
