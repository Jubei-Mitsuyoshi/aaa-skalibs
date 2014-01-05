/* ISC license. */

#include "fmtscan.h"
#include "tai.h"

unsigned int taia_scan (char const *s, struct taia *a)
{
  char pack[TAIA_PACK] ;
  register unsigned int r = ucharn_scan(s, pack, TAIA_PACK) ;
  if (r) taia_unpack(pack, a) ;
  return r ;
}
