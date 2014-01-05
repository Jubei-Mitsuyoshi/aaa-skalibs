/* ISC license. */

#include "uint32.h"
#include "biguint.h"

int bu_mod (uint32 *a, unsigned int an, uint32 const *b, unsigned int bn)
{
  uint32 q[an] ;
  return bu_div(a, an, b, bn, q, an, a, an) ;
}
