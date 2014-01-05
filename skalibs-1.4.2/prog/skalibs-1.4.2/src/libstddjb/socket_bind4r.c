/* ISC license. */

#include "nonposix.h"
#include <sys/socket.h>
#include "uint16.h"
#include "socket.h"

int socket_bind4_reuse (int s, char const *ip, uint16 port)
{
  unsigned int opt = 1 ;
  setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof opt) ;
  return socket_bind4(s, ip, port) ;
}
