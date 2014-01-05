/* ISC license. */

#include "sysdeps.h"

#ifdef HASSPLICE

#include "nonposix.h"
#include <fcntl.h>
#include <sys/uio.h>
#include "buffer.h"
#include "iobuffer.h"

int iobuffer_kfromu (iobufferk_ref k, iobufferu_ref u)
{
  struct iovec v ;
  int r ;
  v.iov_base = buffer_RPEEK(&u->b[0]) ;
  v.iov_len = iobufferu_len(u) ;
  r = vmsplice(k->p[1], &v, 1, 0) ;
  if (r < 0) return 0 ;
  k->n += r ;
  u->b[0].p += r ;
  u->b[1].p = u->b[0].p ;
  return iobufferu_isempty(u) ;
}

#else

#include <errno.h>
#include "iobuffer.h"

int iobuffer_kfromu (iobufferk_ref k, iobufferu_ref u)
{
  (void)k ;
  (void)u ;
  return (errno = ENOSYS, 0) ;
}

#endif
