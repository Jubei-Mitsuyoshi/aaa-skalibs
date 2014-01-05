/* ISC license. */

#include <errno.h>
#include "stralloc.h"
#include "djbunix.h"
#include "unix-transactional.h"

void dd_cancel (dirdescriptor_t_ref dd)
{
  dirdescriptor_t zero = DIRDESCRIPTOR_ZERO ;
  register int e = errno ;
  fd_close(dd->fd) ;
  rm_rf_in_tmp(&dd->new, 0) ;
  stralloc_free(&dd->new) ;
  *dd = zero ;
  errno = e ;
}
