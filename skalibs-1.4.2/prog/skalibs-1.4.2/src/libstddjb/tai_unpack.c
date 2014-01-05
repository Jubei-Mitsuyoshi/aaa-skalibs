/* ISC license. */

#include "uint64.h"
#include "tai.h"

void tai_unpack (char const *s, struct tai *t)
{
  uint64_unpack_big(s, &t->x) ;
}
