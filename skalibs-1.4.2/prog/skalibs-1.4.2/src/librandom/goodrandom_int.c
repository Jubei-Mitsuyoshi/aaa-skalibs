/* ISC license. */

/* MT-unsafe */

#include "rrandom.h"
#include "random-internal.h"
#include "random.h"

unsigned int goodrandom_int (unsigned int n)
{
  return rrandom_readint(&goodrandom_here, n, &unirandom_readb) ;
}
