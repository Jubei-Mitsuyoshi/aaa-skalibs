/* ISC license. */

#include "tai.h"
#include "djbtime.h"

int taia_from_localtmn (struct taia *a, localtmn_t const *l)
{
  struct tai t ;
  if (!tai_from_localtm(&t, &l->tm)) return 0 ;
  a->sec = t ;
  a->nano = l->nano ;
  a->atto = 0 ;
  return 1 ;
}
