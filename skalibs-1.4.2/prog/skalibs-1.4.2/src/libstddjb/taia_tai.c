/* ISC license. */

#include "tai.h"

void taia_tai (struct taia const *ta, struct tai *t)
{
  *t = ta->sec ;
}
