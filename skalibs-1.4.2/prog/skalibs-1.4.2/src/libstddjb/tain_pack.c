/* ISC license. */

#include "uint32.h"
#include "tai.h"

void tain_pack (char *s, struct taia const *t)
{
  tai_pack(s, &t->sec) ;
  uint32_pack_big(s+8, t->nano) ;
}
