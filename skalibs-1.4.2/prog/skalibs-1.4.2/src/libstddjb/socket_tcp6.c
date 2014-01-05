/* ISC license. */

#include "nonposix.h"
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "djbunix.h"
#include "ip46.h"
#include "socket.h"

#ifdef SKALIBS_IPV6_ENABLED

int socket_tcp6_internal (unsigned int flags)
{
  int fd = socket_internal(AF_INET6, SOCK_STREAM, 0, flags) ;
  if (fd < 0) return fd ;
  {
    int option = 1 ;
    if (setsockopt(fd, IPPROTO_IPV6, IPV6_V6ONLY, &option, sizeof(option)) < 0)
    {
      register int e = errno ;
      fd_close(fd) ;
      errno = e ;
      return -1 ;
    }
  }
  return fd ;
}

#else

int socket_tcp6_internal (unsigned int flags)
{
  (void)flags ;
  return (errno = ENOSYS, -1) ;
}

#endif
