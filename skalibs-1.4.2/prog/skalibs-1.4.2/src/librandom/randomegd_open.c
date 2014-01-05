/* ISC license. */

#include <errno.h>
#include "djbunix.h"
#include "webipc.h"
#include "randomegd.h"

int randomegd_open (char const *path)
{
  int s = ipc_stream() ;
  if (s < 0) return -1 ;
  if (ipc_connect(s, path) == -1)
  {
    register int e = errno ;
    fd_close(s) ;
    errno = e ;
    return -1 ;
  }
  return s ;
}
