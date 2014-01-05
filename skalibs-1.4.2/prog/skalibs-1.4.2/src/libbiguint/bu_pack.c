/* ISC license. */

#include "uint32.h"
#include "biguint.h"

void bu_pack (char *s, uint32 const *a, register unsigned int n)
{
  while (n--) uint32_pack(s + (n<<2), a[n]) ;
}
