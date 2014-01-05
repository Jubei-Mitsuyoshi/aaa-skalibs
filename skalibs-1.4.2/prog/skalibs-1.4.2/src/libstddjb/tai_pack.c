/* ISC license. */

#include "uint64.h"
#include "tai.h"

void tai_pack (char *s, struct tai const *t)
{
  uint64_pack_big(s, tai_sec(t)) ;
}
