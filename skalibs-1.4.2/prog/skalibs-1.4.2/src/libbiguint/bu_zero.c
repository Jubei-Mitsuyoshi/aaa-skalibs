/* ISC license. */

#include "uint32.h"
#include "biguint.h"

void bu_zero (register uint32 *z, register unsigned int n)
{
  while (n--) z[n] = 0 ;
}
