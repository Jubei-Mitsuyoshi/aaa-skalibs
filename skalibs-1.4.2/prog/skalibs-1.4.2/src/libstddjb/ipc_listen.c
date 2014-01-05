/* ISC license. */

#include "nonposix.h" 
#include <sys/socket.h>
#include "webipc.h"

int ipc_listen (int s, int backlog)
{
  return listen(s, backlog) ;
}
