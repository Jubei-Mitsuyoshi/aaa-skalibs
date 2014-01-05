/* ISC license. */

#include "fmtscan.h"
#include "tai.h"

unsigned int tain_fmt (char *s, struct taia const *a)
{
  char pack[TAIN_PACK] ;
  tain_pack(pack, a) ;
  return ucharn_fmt(s, pack, TAIN_PACK) ;
}
