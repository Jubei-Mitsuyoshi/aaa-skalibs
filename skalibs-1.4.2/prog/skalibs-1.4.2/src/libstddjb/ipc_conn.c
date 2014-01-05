/* ISC license. */

#include "djbunix.h"
#include "webipc.h"

int ipc_connect (int s, char const *p)
{
  if (!ipc_connect2(s, p)) return -1 ;
  return ndelay_off(s) ;
}
