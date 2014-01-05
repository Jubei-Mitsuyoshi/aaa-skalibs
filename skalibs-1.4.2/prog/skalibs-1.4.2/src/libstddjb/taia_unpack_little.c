/* ISC license. */

#include "uint32.h"
#include "tai.h"

void taia_unpack_little (char const *s, struct taia *t)
{
  uint32_unpack(s, &t->atto) ;
  uint32_unpack(s+4, &t->nano) ;
  tai_unpack_little(s+8, &t->sec) ;
}
