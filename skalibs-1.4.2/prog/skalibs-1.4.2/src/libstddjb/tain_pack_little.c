/* ISC license. */

#include "uint32.h"
#include "tai.h"

void tain_pack_little (char *s, struct taia const *t)
{
  uint32_pack(s, t->nano) ;
  tai_pack_little(s+4, &t->sec) ;
}
