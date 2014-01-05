/* ISC license. */

#include "tai.h"
#include "djbtime.h"

int sysclock_from_localtmn (struct taia *a, localtmn_t const *l)
{
  uint64 u ;
  if (!sysclock_from_localtm(&u, &l->tm)) return 0 ;
  tai_u64(&a->sec, u) ;
  a->nano = l->nano ;
  a->atto = 0 ;
  return 1 ;
}
