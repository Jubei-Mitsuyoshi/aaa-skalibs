/* ISC license. */

#include "uint16.h"
#include "tai.h"
#include "socket.h"

int socket_timeoutconn (int s, char const *ip, uint16 port, unsigned int timeout)
{
  struct taia stamp, deadline ;
  taia_now(&stamp) ;
  taia_addsec(&deadline, &stamp, timeout) ;
  return socket_deadlineconnstamp4(s, ip, port, &deadline, &stamp) ;
}
