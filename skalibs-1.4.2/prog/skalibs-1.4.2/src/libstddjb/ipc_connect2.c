/* ISC license. */

#include "nonposix.h"
#include <errno.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "bytestr.h"
#include "error.h"
#include "webipc.h"

int ipc_connect2 (int s, char const *p)
{
  struct sockaddr_un sa ;
  unsigned int l = str_len(p) ;
  if (l > IPCPATH_MAX) return (errno = EPROTO, 0) ;
  byte_zero((char *) &sa, sizeof sa) ;
  sa.sun_family = AF_UNIX ;
  byte_copy(sa.sun_path, l+1, p) ;
  if (connect(s, (struct sockaddr *)&sa, sizeof sa) == -1)
  {
    if (errno == EINTR) errno = EINPROGRESS ;
    return 0 ;
  }
  return 1 ;
}
