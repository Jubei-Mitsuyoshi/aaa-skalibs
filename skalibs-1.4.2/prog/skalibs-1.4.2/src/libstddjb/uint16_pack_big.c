/* ISC license. */

#include "uint16.h"
#include "bytestr.h"

void uint16_pack_big (char *s, uint16 u)
{
  ((unsigned char *)s)[1] = T8(u) ; u >>= 8 ;
  ((unsigned char *)s)[0] = T8(u) ;
}
