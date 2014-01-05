/* ISC license. */

#include "uint32.h"
#include "tai.h"

void taia_pack_little (char *s, struct taia const *t)
{
  uint32_pack(s, t->atto) ;
  uint32_pack(s+4, t->nano) ;
  tai_pack_little(s+8, &t->sec) ;
}
