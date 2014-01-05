/* ISC license. */

#include "bitarray.h"
#include "functypes.h"
#include "freelist.h"
#include "genset.h"

unsigned int genset_iter (genset_ref g, iterfunc_t_ref f, void *stuff)
{
  unsigned char bits[bitarray_div8(g->max)] ;
  unsigned int i = 0, j = 0, n = 0, m = genset_n(g) ;
  freelist_to_bitarray(bits, g->freelist, g->sp / freelist_size(g->max), g->max) ;
  for (; (i < g->max) && (j < m) ; i++) if (bitarray_peek(bits, i))
  {
    j++ ;
    if ((*f)(g->storage + i * g->esize, stuff)) n++ ;
  }
  return n ;
}
