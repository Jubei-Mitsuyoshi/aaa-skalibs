/* ISC license. */

#include "tai.h"

void taia_sub (struct taia *t, struct taia const *u, struct taia const *v)
{
  struct taia uu = *u ;
  tai_sub(&t->sec, &uu.sec, &v->sec) ;
  t->nano = uu.nano - v->nano ;
  t->atto = uu.atto - v->atto ;
  if (t->atto > uu.atto)
  {
    t->atto += 1000000000U ;
    --t->nano ;
  }
  if (t->nano > uu.nano)
  {
    t->nano += 1000000000U ;
    tai_u64(&t->sec, tai_sec(&t->sec)-1) ;
  }
}
