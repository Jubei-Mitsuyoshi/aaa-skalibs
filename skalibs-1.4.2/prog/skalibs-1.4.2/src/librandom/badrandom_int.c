/* ISC license. */

/* MT-unsafe */

#include "rrandom.h"
#include "random-internal.h"
#include "random.h"

unsigned int badrandom_int (unsigned int n)
{
  return rrandom_readint(&badrandom_here, n, &unirandom_readnb) ;
}
