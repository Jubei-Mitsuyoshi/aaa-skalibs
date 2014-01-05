/* ISC license. */

#include "uint32.h"
#include "tai.h"

void taia_unpack (char const *s, struct taia *t)
{
  tai_unpack(s, &t->sec) ;
  uint32_unpack_big(s+8, &t->nano) ;
  uint32_unpack_big(s+12, &t->atto) ;
}
