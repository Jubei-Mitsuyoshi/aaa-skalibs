/* ISC license. */

#include "fmtscan.h"
#include "tai.h"

unsigned int taia_fmt (char *s, struct taia const *a)
{
  char pack[TAIA_PACK] ;
  taia_pack(pack, a) ;
  return ucharn_fmt(s, pack, TAIA_PACK) ;
}
