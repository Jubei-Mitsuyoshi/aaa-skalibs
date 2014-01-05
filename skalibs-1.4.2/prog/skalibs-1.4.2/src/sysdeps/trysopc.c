/* ISC license. */

#ifndef _XPG4_2
# define _XPG4_2
#endif

#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif

#include <sys/types.h>

#if defined(__FreeBSD__)
# include <sys/param.h>
#endif

#include <sys/socket.h>
#include <sys/un.h>

int main (void)
{
  int s ;
  struct ucred dummy ;
  int len = sizeof(struct ucred) ;
  return getsockopt(s, SOL_SOCKET, SO_PEERCRED, &dummy, &len) ;
}
