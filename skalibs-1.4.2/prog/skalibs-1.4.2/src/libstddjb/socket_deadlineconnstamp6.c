/* ISC license. */

#include <errno.h>
#include "uint16.h"
#include "error.h"
#include "tai.h"
#include "socket.h"

int socket_deadlineconnstamp6 (int s, char const *ip, uint16 port, struct taia const *deadline, struct taia *stamp)
{
  if (socket_connect6(s, ip, port) >= 0) return 1 ;
  if (!error_isagain(errno) && !error_isalready(errno)) return 0 ;
  return socket_waitconn(s, deadline, stamp) ;
}
