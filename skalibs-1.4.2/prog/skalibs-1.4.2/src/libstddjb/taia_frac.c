/* ISC license. */

#include "tai.h"

double taia_frac (struct taia const *t)
{
  return (t->atto * 0.000000001 + t->nano) * 0.000000001 ;
}
