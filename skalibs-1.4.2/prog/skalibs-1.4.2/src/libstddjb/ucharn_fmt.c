/* ISC license. */

#include "fmtscan.h"

unsigned int ucharn_fmt (char *s, char const *key, unsigned int n)
{
  register unsigned int i = 0 ;
  for (; i < n ; i++)
  {
    s[i<<1] = fmtscan_asc((unsigned char)key[i] >> 4) ;
    s[(i<<1)+1] = fmtscan_asc((unsigned char)key[i] & 0xF) ;
  }
  return n << 1 ;
}
