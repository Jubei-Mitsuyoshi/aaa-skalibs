/* ISC license. */

#ifndef BUFALLOC_H
#define BUFALLOC_H

#include "stralloc.h"

typedef struct bufalloc bufalloc, *bufalloc_ref ;
struct bufalloc
{
  stralloc x ;
  unsigned int p ;
  int fd ;
  int (*op) (int, char const *, unsigned int) ;
} ;

#define BUFALLOC_ZERO { STRALLOC_ZERO, 0, -1, 0 }
#define BUFALLOC_INIT(op, fd) { STRALLOC_ZERO, 0, (fd), (op) }
extern void bufalloc_init (bufalloc_ref, int (*)(int, char const *, unsigned int), int) ;
#define bufalloc_shrink(ba) stralloc_shrink(&(ba)->x)
#define bufalloc_free(ba) stralloc_free(&(ba)->x)
#define bufalloc_put(ba, s, n) stralloc_catb(&(ba)->x, s, n)
#define bufalloc_puts(ba, s) stralloc_cats(&(ba)->x, s)
#define bufalloc_putv(ba, v, n) stralloc_catv(&(ba)->x, v, n)
#define bufalloc_fd(ba) ((ba)->fd)
extern int bufalloc_flush (bufalloc_ref) ;
extern void bufalloc_clean (bufalloc_ref) ;
#define bufalloc_len(ba) ((ba)->x.len - (ba)->p)
#define bufalloc_isempty(ba) ((ba)->x.len == (ba)->p)

extern bufalloc_ref bufalloc_1, bufalloc_2 ;

#endif
