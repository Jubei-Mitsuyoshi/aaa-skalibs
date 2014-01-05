/* ISC license. */

#include <errno.h>
#include "unirandom.h"

int unirandom_init (unirandom_ref u)
{
  if (u->initted) return 1 ;
  if (!(*u->init)(&u->data)) return 0 ;
  u->initted = 1 ;
  return 1 ;
}
