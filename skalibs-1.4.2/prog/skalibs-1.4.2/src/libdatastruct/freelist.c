/* ISC license. */

#include "uint32.h"
#include "bytestr.h"
#include "freelist.h"
#ifdef DEBUG
#include "buffer.h"
#include "lolstdio.h"
#endif

unsigned int freelist_get (char const *s, unsigned int max, unsigned int i)
{
  char pack[4] ;
  uint32 n ;
  register unsigned int esize = freelist_size(max) ;
  byte_copy(pack, esize, s + esize * i) ;
  byte_zero(pack + esize, 4 - esize) ;
  uint32_unpack(pack, &n) ;
#ifdef DEBUG
  lolprintf("freelist_get: got freecell number %u\n", n) ;
  buffer_flush(buffer_1) ;
#endif
  return (unsigned int)n ;
}

unsigned int freelist_pop (char const *s, unsigned int *sp, unsigned int max)
{
  register unsigned int esize = freelist_size(max) ;
#ifdef DEBUG
  lolprintf("Entering freelist_pop: %u numbers of size %u, max is %u\n", *sp/esize, esize, max) ;
  buffer_flush(buffer_1) ;
#endif
  if (!*sp) return max ;
  *sp -= esize ;
  return freelist_get(s, max, *sp / esize) ;
}

int freelist_push (char *s, unsigned int *sp, unsigned int max, unsigned int n)
{
  char pack[4] ;
  register unsigned int esize = freelist_size(max) ;
  if (*sp / esize >= max) return 0 ;
  uint32_pack(pack, (uint32)n) ;
  byte_copy(s + *sp, esize, pack) ;
  *sp += esize ;
  return 1 ;
}

int freelist_init (char *s, unsigned int *sp, unsigned int oldmax, unsigned int newmax)
{
  unsigned int esize = freelist_size(newmax) ;
  char pack[4] ;
  register uint32 i = newmax ;
#ifdef DEBUG
  lolprintf("freelist_init: sp is %u, adding freecells from %u to %u\n", *sp/esize, oldmax, newmax) ;
  buffer_flush(buffer_1) ;
#endif
  for (; i > oldmax ; i--)
  {
    uint32_pack(pack, i-1) ;
    byte_copy(s + *sp, esize, pack) ;
    *sp += esize ;
  }
  return 1 ;
}
