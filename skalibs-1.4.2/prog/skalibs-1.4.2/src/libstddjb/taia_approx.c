/* ISC license. */

#include "tai.h"

double taia_approx (struct taia const *t)
{
  return tai_approx(&t->sec) + taia_frac(t) ;
}
