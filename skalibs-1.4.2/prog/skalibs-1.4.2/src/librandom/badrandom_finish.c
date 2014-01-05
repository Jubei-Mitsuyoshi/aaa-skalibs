/* ISC license. */

/* MT-unsafe */

#include "rrandom.h"
#include "random-internal.h"
#include "random.h"

void badrandom_finish (void)
{
  rrandom_finish(&badrandom_here) ;
}
