/* ISC license. */

#include "tai.h"

int taia_less (struct taia const *t, struct taia const *u)
{
  if (tai_sec(&t->sec) < tai_sec(&u->sec)) return 1 ;
  if (tai_sec(&t->sec) > tai_sec(&u->sec)) return 0 ;
  if (t->nano < u->nano) return 1 ;
  if (t->nano > u->nano) return 0 ;
  return t->atto < u->atto ;
}
