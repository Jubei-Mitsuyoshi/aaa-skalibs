/* ISC license. */

#include "tai.h"
#include "djbtime.h"

int localtmn_from_taia (localtmn_t_ref l, struct taia const *a, int tz)
{
  struct tm t ;
  if (!localtm_from_tai(&t, taia_secp(a), tz)) return 0 ;
  l->tm = t ;
  l->nano = a->nano ;
  return 1 ;
}
