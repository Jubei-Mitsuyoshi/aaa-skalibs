/* ISC license. */

#include <errno.h>
#include "uint32.h"
#include "biguint.h"

int bu_copy (uint32 *b, unsigned int bn, uint32 const *a, unsigned int an)
{
  register unsigned int alen = bu_len(a, an) ;
  if (bn < alen)
  {
    bu_copy_internal(b, a, bn) ;
    return (errno = EOVERFLOW, 0) ;
  }
  bu_copy_internal(b, a, alen) ;
  bu_zero(b + alen, bn - alen) ;
  return 1 ;
}
