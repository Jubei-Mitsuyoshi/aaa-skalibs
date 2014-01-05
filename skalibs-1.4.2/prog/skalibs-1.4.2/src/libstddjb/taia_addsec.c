/* ISC license. */

#include "tai.h"

void taia_addsec (struct taia *b, struct taia const *a, int c)
{
  b->atto = a->atto ;
  b->nano = a->nano ;
  if (c >= 0)
  {
    struct tai t ;
    tai_u64(&t, c) ;
    tai_add(&b->sec, &a->sec, &t) ;
  }
  else
  {
    struct tai t ;
    tai_u64(&t, -c) ;
    tai_sub(&b->sec, &a->sec, &t) ;
  }
}
