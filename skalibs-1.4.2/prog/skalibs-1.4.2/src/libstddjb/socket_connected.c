/* ISC license. */

#include "nonposix.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include "allreadwrite.h"
#include "socket.h"

int socket_connected (int s)
{
  struct sockaddr_in sa ;
  socklen_t dummy = sizeof sa ;
  if (getpeername(s, (struct sockaddr *)&sa, &dummy) == -1)
  {
    char ch ;
    fd_read(s, &ch, 1) ; /* sets errno */
    return 0 ;
  }
  return 1 ;
}
