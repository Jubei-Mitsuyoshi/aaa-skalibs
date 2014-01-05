/* ISC license. */

#include "nonposix.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include "uint16.h"
#include "bytestr.h"
#include "socket.h"

int socket_remote4 (int s, char *ip, uint16 *port)
{
  struct sockaddr_in sa ;
  socklen_t dummy = sizeof sa ;

  if (getpeername(s, (struct sockaddr *)&sa, &dummy) == -1)
    return -1 ;
  byte_copy(ip, 4, (char *)&sa.sin_addr.s_addr) ;
  uint16_unpack_big((char *)&sa.sin_port, port) ;
  return 0 ;
}
