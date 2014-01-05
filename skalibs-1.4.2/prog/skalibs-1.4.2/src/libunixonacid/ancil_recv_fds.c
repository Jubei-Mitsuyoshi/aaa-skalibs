/* ISC license. */

#include "nonposix.h"
#include <sys/socket.h>
#include <sys/uio.h>
#include "ancillary.h"

int ancil_recv_fds (int sock, int *fds, unsigned int n)
{
  struct msghdr msghdr ;
  struct iovec nothing_ptr ;
  struct cmsghdr *cmsg ;
  char buf[sizeof(struct cmsghdr) + n * sizeof(int)] ;
  char nothing ;
  register unsigned int i = 0 ;

  nothing_ptr.iov_base = &nothing ;
  nothing_ptr.iov_len = 1 ;
  msghdr.msg_name = 0 ;
  msghdr.msg_namelen = 0 ;
  msghdr.msg_iov = &nothing_ptr ;
  msghdr.msg_iovlen = 1 ;
  msghdr.msg_flags = 0 ;
  msghdr.msg_control = buf ;
  msghdr.msg_controllen = sizeof(buf) ;
  cmsg = CMSG_FIRSTHDR(&msghdr) ;
  cmsg->cmsg_len = msghdr.msg_controllen ;
  cmsg->cmsg_level = SOL_SOCKET ;
  cmsg->cmsg_type = SCM_RIGHTS ;
  for (; i < n ; i++) ((int *)CMSG_DATA(cmsg))[i] = -1 ;
  if (recvmsg(sock, &msghdr, 0) < 0) return -1 ;
  for (i = 0 ; i < n ; i++) fds[i] = ((int *)CMSG_DATA(cmsg))[i] ;
  n = (cmsg->cmsg_len - sizeof(struct cmsghdr)) / sizeof(int) ;
  return n ;
}
