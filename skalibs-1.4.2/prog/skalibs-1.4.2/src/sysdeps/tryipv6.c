/* ISC license. */

#ifndef _XPG4_2
# define _XPG4_2
#endif

#include <sys/types.h>

#if defined(__FreeBSD__)
# include <sys/param.h>
#endif

#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main (void)
{
  int s ;
  register int r ;
  struct in6_addr foo = IN6ADDR_LOOPBACK_INIT ;
  struct sockaddr_in6 bar ;
  memset(&bar, 0, sizeof(struct sockaddr_in6)) ;
  bar.sin6_addr = foo ;
  bar.sin6_port = 1026 ;
  s = socket(AF_INET6, SOCK_STREAM, 0) ;
  if (s < 0) return 111 ;
  do r = connect(s, (struct sockaddr *)&bar, sizeof bar) ;
  while ((r == -1) && (errno == EINTR)) ;
  if ((r == -1) && (errno == EALREADY)) errno = EINPROGRESS ;
  return 0 ;
}
