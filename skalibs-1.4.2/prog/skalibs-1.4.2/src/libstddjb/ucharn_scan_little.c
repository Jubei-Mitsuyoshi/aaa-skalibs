/* ISC license. */

#include "fmtscan.h"

unsigned int ucharn_scan_little (char const *s, char *key, unsigned int n)
{
  register unsigned int i = 0 ;
  for (; i < n ; i++)
  {
    unsigned char c = fmtscan_num(s[(i<<1)+1], 16) ;
    if (c > 0xF) return 0 ;
    key[i] = c << 4 ;
    c = fmtscan_num(s[i<<1], 16) ;
    if (c > 0xF) return 0 ;
    key[i] += c ;
  }
  return n << 1 ;
}
