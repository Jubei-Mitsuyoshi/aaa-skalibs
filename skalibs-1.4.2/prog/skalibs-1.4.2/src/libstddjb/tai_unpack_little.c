/* ISC license. */

#include "uint64.h"
#include "tai.h"

void tai_unpack_little (char const *s, struct tai *t)
{
  uint64_unpack(s, &t->x) ;
}
