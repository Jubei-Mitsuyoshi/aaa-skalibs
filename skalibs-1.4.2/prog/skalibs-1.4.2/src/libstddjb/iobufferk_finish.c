/* ISC license. */

#include "sysdeps.h"

#ifdef HASSPLICE

#include <errno.h>
#include "djbunix.h"
#include "iobuffer.h"

static void iobufferk_nop (iobufferk_ref k)
{
  (void)k ;
}

static void iobufferk_finish_0 (iobufferk_ref k)
{
  register int e = errno ;
  fd_close(k->p[1]) ;
  errno = e ;
}

static void iobufferk_finish_3 (iobufferk_ref k)
{
  register int e = errno ;
  fd_close(k->p[1]) ;
  fd_close(k->p[0]) ;
  errno = e ;
}

iobufferk_finish_func_t_ref const iobufferk_finish_f[4] =
{
  &iobufferk_finish_0, &iobufferk_nop, &iobufferk_nop, &iobufferk_finish_3
} ;

#else

#include "iobuffer.h"

static void iobufferk_nop (iobufferk_ref k)
{
  (void)k ;
}

iobufferk_finish_func_t_ref const iobufferk_finish_f[4] =
{
  &iobufferk_nop, &iobufferk_nop, &iobufferk_nop, &iobufferk_nop
} ;

#endif
