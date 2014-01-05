/* ISC license. */

#include "getpeereid.h"
#include "webipc.h"

int ipc_eid (int s, unsigned int *u, unsigned int *g)
{
  int dummyu, dummyg ;
  if (getpeereid(s, &dummyu, &dummyg) < 0) return -1 ;
  *u = (unsigned int)dummyu ;
  *g = (unsigned int)dummyg ;
  return 0 ;
}
