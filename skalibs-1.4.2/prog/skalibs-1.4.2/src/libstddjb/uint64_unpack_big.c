/* ISC license. */

#include "uint64.h"
#include "bytestr.h"

void uint64_unpack_big (char const *s, uint64 *u)
{
  uint64 r = T8((unsigned char)s[0]) ; r <<= 8 ;
  r += T8((unsigned char)s[1]) ; r <<= 8 ;
  r += T8((unsigned char)s[2]) ; r <<= 8 ;
  r += T8((unsigned char)s[3]) ; r <<= 8 ;
  r += T8((unsigned char)s[4]) ; r <<= 8 ;
  r += T8((unsigned char)s[5]) ; r <<= 8 ;
  r += T8((unsigned char)s[6]) ; r <<= 8 ;
  r += T8((unsigned char)s[7]) ;
  *u = r ;
}
