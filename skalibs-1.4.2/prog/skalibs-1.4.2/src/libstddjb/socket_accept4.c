/* ISC license. */

#include "sysdeps.h"
#include "nonposix.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include "uint16.h"
#include "bytestr.h"
#include "djbunix.h"
#include "socket.h"

int socket_accept4_internal (int s, char *ip, uint16 *port, unsigned int options)
{
  struct sockaddr_in sa ;
  socklen_t dummy = sizeof sa ;
  register int fd ;
  do
#ifdef HASACCEPT4
    fd = accept4(s, (struct sockaddr *)&sa, &dummy, ((options & DJBUNIX_FLAG_NB) ? SOCK_NONBLOCK : 0) | ((options & DJBUNIX_FLAG_COE) ? SOCK_CLOEXEC : 0)) ;
#else
    fd = accept(s, (struct sockaddr *)&sa, &dummy) ;
#endif
  while ((fd < 0) && (errno == EINTR)) ;
  if (fd < 0) return -1 ;
#ifndef HASACCEPT4
  if ((((options & DJBUNIX_FLAG_NB) ? ndelay_on(fd) : ndelay_off(fd)) < 0)
   || (((options & DJBUNIX_FLAG_COE) ? coe(fd) : uncoe(fd)) < 0))
  {
    register int e = errno ;
    fd_close(fd) ;
    errno = e ;
    return -1 ;
  }
#endif
  byte_copy(ip, 4, (char *)&sa.sin_addr.s_addr) ;
  uint16_unpack_big((char *)&sa.sin_port, port) ;
  return fd ;
}
