/* ISC license. */

#include "bytestr.h"
#include "stralloc.h"
#include "freelist.h"
#include "gensetdyn.h"
#ifdef DEBUG
#include "buffer.h"
#include "lolstdio.h"
#endif

int gensetdyn_ready (gensetdyn_ref g, unsigned int n)
{
  int wasnull = !g->storage.s ;
  register unsigned int oldsize, newsize ;
  if (n < g->storage.len) return 1 ;
#ifdef DEBUG
  lolprintf("Entering gensetdyn_ready: wanting at least %u objects\n", n) ;
#endif
  n += g->base + (n * g->fracnum) / g->fracden ;
#ifdef DEBUG
  lolprintf("Allocating for %u objects of size %u\n", n, g->esize) ;
  buffer_flush(buffer_1) ;
#endif
  oldsize = freelist_size(g->storage.len) ;
  newsize = freelist_size(n) ;
  if (!stralloc_ready_tuned(&g->storage, n * g->esize, 0, 0, 1)) return 0 ;
  if (!stralloc_ready_tuned(&g->freelist, newsize * n + (oldsize == newsize ? 0 : g->freelist.len), 0, 0, 1))
  {
    if (wasnull) stralloc_free(&g->storage) ;
    return 0 ;
  }
  if (newsize != oldsize)
  {
    char *tmp = g->freelist.s + newsize * n ;
    register unsigned int m = g->freelist.len / oldsize, i = 0 ;
    byte_copyr(tmp, g->freelist.len, g->freelist.s) ;
    g->freelist.len = 0 ;
    for (; i < m ; i++)
    {
      byte_copy(tmp, oldsize, g->freelist.s + g->freelist.len) ;
      byte_zero(g->freelist.s + g->freelist.len + oldsize, newsize - oldsize) ;
      tmp += oldsize ; g->freelist.len += newsize ;
    }
  }
  freelist_init(g->freelist.s, &g->freelist.len, g->storage.len, n) ;
  g->storage.len = n ;
  return 1 ;
}
