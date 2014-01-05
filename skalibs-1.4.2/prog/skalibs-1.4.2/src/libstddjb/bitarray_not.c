/* ISC license. */

#include "bitarray.h"

void bitarray_not (register unsigned char *s, register unsigned int a, register unsigned int b)
{
  if (!b) return ;
  b += a ;
  if ((a >> 3) == ((b-1) >> 3))
    s[a>>3] ^= ((1 << (a & 7)) - 1) ^ ((a << (b & 7)) - 1) ;
  else
  {
    register unsigned int i = (a>>3) + 1 ;
    s[a>>3] ^= ~((1 << (a & 7)) - 1) ;
    for (; i < (b>>3) - 1 ; i++) s[i] = ~s[i] ;
    s[b>>3] ^= (1 << (b & 7)) - 1 ;
  }
}
