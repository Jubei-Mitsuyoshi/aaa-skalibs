/* ISC license. */

#include <errno.h>
#include "unirandom.h"

unsigned int unirandom_readb (unirandom_ref u, char *s, unsigned int n)
{
  if (!u->initted && !unirandom_init(u)) return 0 ;
  return (*u->readb)(&u->data, s, n) ;
}
