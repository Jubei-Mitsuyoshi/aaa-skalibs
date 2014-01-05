/* ISC license. */

#include "uint16.h"
#include "uint32.h"
#include "tai.h"
#include "socket.h"

int socket_deadlineconnstamp4_u32 (int s, uint32 ip, struct taia const *deadline, struct taia *stamp)
{
  char pack[4] ;
  uint32_pack_big(pack, ip) ;
  return socket_deadlineconnstamp4(s, pack, deadline, stamp) ;
}
