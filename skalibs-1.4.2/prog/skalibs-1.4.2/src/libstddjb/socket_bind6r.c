/* ISC license. */

#include "nonposix.h"
#include <sys/socket.h>
#include "uint16.h"
#include "socket.h"

int socket_bind6_reuse (int s, char const *ip6, uint16 port)
{
  unsigned int opt = 1 ;
  setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof opt) ;
  return socket_bind6(s, ip6, port) ;
}
