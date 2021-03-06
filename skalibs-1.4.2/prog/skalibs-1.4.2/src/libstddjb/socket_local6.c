/* ISC license. */

#include "nonposix.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include "uint16.h"
#include "bytestr.h"
#include "socket.h"
#include "ip46.h"

#ifdef SKALIBS_IPV6_ENABLED

int socket_local6 (int s, char *ip, uint16 *port)
{
  struct sockaddr_in6 sa ;
  socklen_t dummy = sizeof sa ;

  if (getsockname(s, (struct sockaddr *)&sa, &dummy) == -1)
    return -1 ;
  byte_copy(ip, 16, sa.sin6_addr.s6_addr) ;
  uint16_unpack_big((char *)&sa.sin6_port, port) ;
  return 0 ;
}

#else

#include <errno.h>

int socket_local6 (int s, char *ip, uint16 *port)
{
  (void)s ;
  (void)ip ;
  (void)port ;
  return (errno = ENOSYS, -1) ;
}

#endif
