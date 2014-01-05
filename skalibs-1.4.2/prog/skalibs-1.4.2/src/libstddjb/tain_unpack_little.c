/* ISC license. */

#include "uint32.h"
#include "tai.h"

void tain_unpack_little (char const *s, struct taia *t)
{
  t->atto = 0 ;
  uint32_unpack(s, &t->nano) ;
  tai_unpack_little(s+4, &t->sec) ;
}
