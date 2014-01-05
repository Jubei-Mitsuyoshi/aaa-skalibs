/* ISC license. */

#include "nonposix.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include "socket.h"

int socket_tcpnodelay (int s)
{
  static int const opt = TCP_NODELAY ;
  return setsockopt(s, IPPROTO_TCP, 1, &opt, sizeof(int)) ;
}
