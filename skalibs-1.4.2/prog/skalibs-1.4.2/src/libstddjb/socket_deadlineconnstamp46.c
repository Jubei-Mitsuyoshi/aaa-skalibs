/* ISC license. */

#include <errno.h>
#include "uint16.h"
#include "error.h"
#include "tai.h"
#include "socket.h"
#include "ip46.h"

int socket_deadlineconnstamp46 (int s, ip46_t const *i, uint16 port, struct taia const *deadline, struct taia *stamp)
{
  if (socket_connect46(s, i, port) >= 0) return 1 ;
  if (!error_isagain(errno) && !error_isalready(errno)) return 0 ;
  return socket_waitconn(s, deadline, stamp) ;
}
