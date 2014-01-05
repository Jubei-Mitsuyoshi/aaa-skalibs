/* ISC license. */

#include "tai.h"

void taia_half (struct taia *t, struct taia const *u)
{
  t->atto = u->atto>>1 ;
  if (u->nano & 1) t->atto += 500000000U ;
  t->nano = u->nano>>1 ;
  if (tai_sec(&u->sec) & 1) t->nano += 500000000U ;
  tai_u64(&t->sec, tai_sec(&u->sec)>>1) ;
}
