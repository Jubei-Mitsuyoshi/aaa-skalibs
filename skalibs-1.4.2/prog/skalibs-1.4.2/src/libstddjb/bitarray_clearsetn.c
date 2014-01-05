/* ISC license. */

#include "bitarray.h"

void bitarray_clearsetn (register unsigned char *s, register unsigned int a, register unsigned int b, register int h)
{
  if (!b) return ;
  b += a ;
  if ((a >> 3) == ((b-1) >> 3))
  {
    register unsigned char mask = ((1 << (a & 7)) - 1) ^ ((a << (b & 7)) - 1) ;
    if (h) s[a>>3] |= mask ; else s[a>>3] &= ~mask ;
  }
  else
  {
    register unsigned char mask = ~((1 << (a & 7)) - 1) ;
    register unsigned int i = (a>>3) + 1 ;
    if (h) s[a>>3] |= mask ; else s[a>>3] &= ~mask ;
    mask = h ? ~'\0' : '\0' ;
    for (; i < (b>>3) - 1 ; i++) s[i] = mask ;
    mask = (1 << (b & 7)) - 1 ;
    if (h) s[b>>3] |= mask ; else s[b>>3] &= ~mask ;
  }
}
