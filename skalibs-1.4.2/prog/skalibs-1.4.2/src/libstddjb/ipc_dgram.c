/* ISC license. */

#include "nonposix.h"
#include <sys/socket.h>
#include "djbunix.h"
#include "webipc.h"

int ipc_datagram_internal (unsigned int flags)
{
  return socket_internal(AF_UNIX, SOCK_DGRAM, 0, flags) ;
}
