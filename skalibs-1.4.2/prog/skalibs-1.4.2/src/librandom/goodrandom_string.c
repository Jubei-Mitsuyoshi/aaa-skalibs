/* ISC license. */

/* MT-unsafe */

#include "rrandom.h"
#include "random-internal.h"
#include "random.h"

unsigned int goodrandom_string (char *s, unsigned int n)
{
  return rrandom_readb(&goodrandom_here, s, n) ;
}
