/* ISC license. */

#include "uint32.h"
#include "biguint.h"

unsigned int bu_len (register uint32 const *a, register unsigned int n)
{
  while (n--) if (a[n]) return n+1 ;
  return 0 ;
}
