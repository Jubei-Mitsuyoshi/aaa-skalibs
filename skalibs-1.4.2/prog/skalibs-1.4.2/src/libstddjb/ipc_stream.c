/* ISC license. */

#include "nonposix.h"
#include <sys/socket.h>
#include "djbunix.h"
#include "webipc.h"

int ipc_stream_internal (unsigned int flags)
{
  return socket_internal(AF_UNIX, SOCK_STREAM, 0, flags) ;
}
