/* ISC license. */

#include "tai.h"

int taia_sysclock (struct taia *a)
{
  struct taia aa ;
  if (!sysclock_get(&aa)) return 0 ;
  if (!tai_from_sysclock(&a->sec, aa.sec.x)) return 0 ;
  a->nano = aa.nano ; a->atto = aa.atto ;
  return 1 ;
}

