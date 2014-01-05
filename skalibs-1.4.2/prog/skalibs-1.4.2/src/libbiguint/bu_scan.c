/* ISC license. */

#include <errno.h>
#include "uint32.h"
#include "bitarray.h"
#include "biguint.h"

int bu_scan (char const *s, unsigned int len, uint32 *x, unsigned int xn, unsigned int zeron)
{
  register unsigned int n = bitarray_div8(zeron) ;
  if (xn < n) return (errno = EOVERFLOW, 0) ;
  bu_scan_internal(s, len, x) ;
  bu_zero(x + n, xn - n) ;
  return 1 ;
}
