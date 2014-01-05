/* ISC license. */

#include "uint64.h"
#include "tai.h"

void tai_pack_little (char *s, struct tai const *t)
{
  uint64_pack(s, tai_sec(t)) ;
}
