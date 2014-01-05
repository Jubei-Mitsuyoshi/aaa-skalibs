/* ISC license. */

#include <errno.h>
#include "uint16.h"
#include "fmtscan.h"

unsigned int ip6_scan (char const *s, char *ip6)
{
  static const unsigned char class[256] = "2222222222222222222222222222222222222222222222220000000000122222200000022222222222222222222222222000000222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222" ;
  static const unsigned char table[5][3] = { "\024#\005", "\024\"\005", "\024\005\006", "\005\002\005", "\024\t\016" } ;
  uint16 tmp[8] = { 0, 0, 0, 0, 0, 0, 0, 0 } ;
  unsigned int pos = 8, j = 0, state = 0, i = 0 ;

  while (state < 5)
  {
    register unsigned char c = table[state][class[(unsigned char)s[i]] - '0'] ;
    state = c & 7 ;
    if (c & 0x20) { if (pos < 8) state = 5 ; else pos = j ; }
    if (c & 0x10)
    {
     if (tmp[j] & 0xf000) state = 5 ;
     else tmp[j] = (tmp[j] << 4) + fmtscan_num(s[i], 16) ;
    }
    if (c & 0x08) if ((++j > 7) && (state < 5)) state = 5 ;
    i++ ;
  }

  if (((pos < 8) && (j > 6)) || ((pos == 8) && (j < 8))) state = 5 ;
  if (state == 5) return (errno = EINVAL, 0) ; 
  for (state = j ; state > pos ; state--) tmp[state - j + 7] = tmp[state - 1] ;
  for (; state < pos + 8 - j ; state++) tmp[state] = 0 ;

  for (j = 0 ; j < 8 ; j++) uint16_pack_big(ip6 + (j<<1), tmp[j]) ;
  return i - 1 ;
}
