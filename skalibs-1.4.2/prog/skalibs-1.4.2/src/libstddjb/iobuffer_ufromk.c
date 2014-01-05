/* ISC license. */

#include "sysdeps.h"

#ifdef HASSPLICE

#include "iobuffer.h"

int iobuffer_ufromk (iobufferu_ref u, iobufferk_ref k)
{
  int in = u->b[0].fd ;
  u->b[0].fd = k->p[0] ;
  while (k->n)
  {
    register int r = iobufferu_fill(u) ;
    if (r <= 0) goto err ;
    k->n -= r ;
  }
  u->b[0].fd = in ;
  return 1 ;

 err:
  u->b[0].fd = in ;
  return 0 ;
}

#else

#include <errno.h>
#include "iobuffer.h"

int iobuffer_ufromk (iobufferu_ref u, iobufferk_ref k)
{
  (void)u ;
  (void)k ;
  return (errno = ENOSYS, 0) ;
}

#endif
