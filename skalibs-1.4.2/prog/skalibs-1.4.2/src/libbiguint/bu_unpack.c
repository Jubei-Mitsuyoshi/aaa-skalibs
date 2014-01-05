/* ISC license. */

#include "uint32.h"
#include "biguint.h"

void bu_unpack (char const *s, uint32 *a, register unsigned int n)
{
  while (n--) uint32_unpack(s + (n<<2), a + n) ;
}
