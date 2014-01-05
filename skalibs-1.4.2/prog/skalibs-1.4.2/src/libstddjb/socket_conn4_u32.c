/* ISC license. */

#include "uint16.h"
#include "uint32.h"
#include "socket.h"

int socket_connect4_u32 (int s, uint32 ip, uint16 port)
{
  char pack[4] ;
  uint32_pack_big(pack, ip) ;
  return socket_connect4(s, pack, port) ;
}
