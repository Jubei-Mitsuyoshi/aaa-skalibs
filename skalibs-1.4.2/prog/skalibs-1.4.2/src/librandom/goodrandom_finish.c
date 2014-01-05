/* ISC license. */

/* MT-unsafe */

#include "random-internal.h"
#include "rrandom.h"
#include "random.h"

void goodrandom_finish (void)
{
  rrandom_finish(&goodrandom_here) ;
}
