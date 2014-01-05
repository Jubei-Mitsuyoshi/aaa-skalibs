/* ISC license. */

#ifndef ANCILLARY_H
#define ANCILLARY_H

extern int ancil_send_fds (int, int const *, unsigned int) ;
 /* returns number of fds actually sent */

extern int ancil_recv_fds (int, int *, unsigned int) ;
 /* returns number of fds actually received */
 
#define ancil_send_fd(sock, fd) ancil_send_fds(sock, &(fd), 1)
#define ancil_recv_fd(sock, fdp) ancil_recv_fds(sock, (fdp), 1)

#endif
