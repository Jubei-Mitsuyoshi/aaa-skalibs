/* ISC license. */

#include "bitarray.h"
#include "freelist.h"

void freelist_to_bitarray (unsigned char *s, char const *freelist, unsigned int sp, unsigned int max)
{
  register unsigned int i = 0 ;
  bitarray_setn(s, 0, max) ;
  for (; i < sp ; i++)
  {
    register unsigned int j = freelist_get(freelist, max, i) ;
    bitarray_clear(s, j) ;
  }
}
