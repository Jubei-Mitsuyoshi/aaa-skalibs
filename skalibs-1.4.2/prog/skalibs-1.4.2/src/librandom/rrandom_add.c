/* ISC license. */

#include <errno.h>
#include "unirandom.h"
#include "rrandom.h"

int rrandom_add (rrandom_ref z, int (*f) (unirandom_ref))
{
  if (z->n >= 3) return (errno = EBUSY, 0) ;
  if (!(*f)(&z->tries[z->n].it)) return 0 ;
  z->tries[z->n++].ok = 3 ;
  return 1 ;
}
