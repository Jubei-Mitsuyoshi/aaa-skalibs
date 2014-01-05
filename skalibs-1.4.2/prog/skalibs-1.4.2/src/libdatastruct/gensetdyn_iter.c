/* ISC license. */

#include "bitarray.h"
#include "functypes.h"
#include "freelist.h"
#include "gensetdyn.h"

unsigned int gensetdyn_iter (gensetdyn_ref g, iterfunc_t_ref f, void *stuff)
{
 /*
    XXX: we may be called by a freeing function, so we cannot alloc -
    XXX: so pray that the bitarray fits in the stack.
 */
  unsigned char bits[bitarray_div8(g->storage.len)] ;
  unsigned int i = 0, j = 0, n = 0, m = gensetdyn_n(g) ;
  freelist_to_bitarray(bits, g->freelist.s, g->freelist.len / freelist_size(g->storage.len), g->storage.len) ;
  for (; (i < g->storage.len) && (j < m) ; i++) if (bitarray_peek(bits, i))
  {
    j++ ;
    if ((*f)(gensetdyn_p(g, i), stuff)) n++ ;
  }
  return n ;
}
