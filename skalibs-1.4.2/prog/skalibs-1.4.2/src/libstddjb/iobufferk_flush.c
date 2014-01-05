/* ISC license. */

#include "sysdeps.h"

#ifdef HASSPLICE

#include "nonposix.h"
#include <fcntl.h>
#include <errno.h>
#include "iobuffer.h"

static int iobufferk_flush_0 (iobufferk_ref k)
{
  unsigned int w = 0 ;
  while (k->n)
  {
    register int r = splice(k->fd[0], 0, k->p[1], 0, k->n, 0) ;
    if (r < 0) return r ;
    else if (!r) break ;
    k->n -= r ; w += r ;
  }
  return (int)w ;
}

static int fakeflush (iobufferk_ref k)
{
  register unsigned int n = k->n ;
  k->n = 0 ;
  return (int)n ;
}

static int iobufferk_flush_3 (iobufferk_ref k)
{
  unsigned int w = 0 ;
  while (k->n)
  {
    register int r = splice(k->p[0], 0, k->fd[1], 0, k->n, SPLICE_F_MORE | (k->nb & 2 ? SPLICE_F_NONBLOCK : 0)) ;
    if (r < 0)
    {
      if (errno == EINVAL) errno = ENOSYS ;
      return r ;
    }
    else if (!r) return (errno = EPIPE, -1) ;
    k->n -= r ; w += r ;
  }
  return (int)w ;
}

iobufferk_io_func_t_ref const iobufferk_flush_f[4] =
{
  &iobufferk_flush_0, &fakeflush, &fakeflush, &iobufferk_flush_3
} ;

#else

#include <errno.h>
#include "iobuffer.h"

iobufferk_io_func_t_ref const iobufferk_flush_f[4] =
{
  &iobufferk_nosys, &iobufferk_nosys, &iobufferk_nosys, &iobufferk_nosys
} ;

#endif
