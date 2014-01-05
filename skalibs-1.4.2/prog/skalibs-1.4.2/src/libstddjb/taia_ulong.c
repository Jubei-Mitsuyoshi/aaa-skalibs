/* ISC license. */

#include "tai.h"

void taia_ulong (struct taia *t, unsigned long s)
{
  tai_u64(&t->sec, s) ;
  t->nano = t->atto = 0 ;
}
