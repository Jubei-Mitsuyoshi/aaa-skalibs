/* ISC license. */

/* MT-unsafe */

#include "rrandom.h"
#include "random-internal.h"
#include "random.h"

unsigned int badrandom_string (char *s, unsigned int n)
{
  return rrandom_readnb(&badrandom_here, s, n) ;
}
