/* ISC license. */

#include "uint32.h"
#include "fmtscan.h"

unsigned int ip4_fmtu32 (char *s, uint32 ip)
{
  char pack[4] ;
  uint32_pack_big(pack, ip) ;
  return ip4_fmt(s, pack) ;
}
