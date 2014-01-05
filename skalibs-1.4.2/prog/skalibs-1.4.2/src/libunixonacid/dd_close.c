/* ISC license. */

#include "djbunix.h"
#include "unix-transactional.h"

int dd_close (dirdescriptor_t_ref dd)
{
  return (fd_close(dd->fd) >= 0) ;
}
