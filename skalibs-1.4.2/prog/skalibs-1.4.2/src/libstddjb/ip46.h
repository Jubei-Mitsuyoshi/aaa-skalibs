/* ISC license. */

#ifndef IP46_H
#define IP46_H

#include <errno.h>
#include "sysdeps.h"
#include "skalibs-config.h"
#include "uint16.h"
#include "bytestr.h"
#include "fmtscan.h"
#include "tai.h"
#include "socket.h"

#define IP46_FMT IP6_FMT
#define IP4_ANY "\0\0\0"
#define IP6_ANY   "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define IP4_LOCAL "\177\0\0\1"
#define IP6_LOCAL "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1"

typedef struct ip46full_s ip46full_t, *ip46full_t_ref ;

struct ip46full_s
{
  char ip[16] ;
  unsigned int is6: 1 ;
} ;
#define IP46FULL_ZERO { .ip = IP6_ANY, .is6 = 0 }

#define ip46full_is6(i) ((i)->is6)
#define ip46full_fmt(s, i) ((i)->is6 ? ip6_fmt(s, (i)->ip) : ip4_fmt(s, (i)->ip))
extern unsigned int ip46full_scan (char const *, ip46full_t_ref) ;
extern unsigned int ip46full_scanlist (ip46full_t_ref, unsigned int, char const *, unsigned int *) ;
#define ip46full_from_ip4(i, ip4) (byte_copy((i)->ip, 4, ip4), byte_zero((i)->ip + 4, 12), (i)->is6 = 0)
#define ip46full_from_ip6(i, ip6) (byte_copy((i)->ip, 16, ip6), (i)->is6 = 1)

#if defined(HASIPV6) && defined(SKALIBS_FLAG_WANTIPV6)

typedef ip46full_t ip46_t, *ip46_t_ref ;
#define IP46_ZERO IP46FULL_ZERO

#define SKALIBS_IPV6_ENABLED
#define SKALIBS_IP_SIZE 16
#define ip46_is6(i) ip46full_is6(i)
#define ip46_fmt(s, i) ip46full_fmt(s, i)
#define ip46_scan(s, i) ip46full_scan(s, i)
#define ip46_scanlist(out, max, s, num) ip46full_scanlist(out, max, s, num)
#define ip46_from_ip4(i, ip4) (ip46full_from_ip4(i, ip4), 1)
#define ip46_from_ip6(i, ip6) (ip46full_from_ip6(i, ip6), 1)

#define socket_connect46(s, i, port) ((i)->is6 ? socket_connect6(s, (i)->ip, port) : socket_connect4(s, (i)->ip, port))
#define socket_bind46(s, i, port) ((i)->is6 ? socket_bind6(s, (i)->ip, port) : socket_bind4(s, (i)->ip, port))
#define socket_bind46_reuse(s, i, port) ((i)->is6 ? socket_bind6_reuse(s, (i)->ip, port) : socket_bind4_reuse(s, (i)->ip, port))
#define socket_tcp46(h) ((h) ? socket_tcp6() : socket_tcp4())
#define socket_udp46(h) ((h) ? socket_udp6() : socket_udp4())
#define socket_recv46(fd, s, len, i, port) ((i)->is6 ? socket_recv6(fd, s, len, (i)->ip, port) : socket_recv4(fd, s, len, (i)->ip, port))
#define socket_send46(fd, s, len, i, port) ((i)->is6 ? socket_send6(fd, s, len, (i)->ip, port) : socket_send4(fd, s, len, (i)->ip, port))
extern int socket_local46 (int, ip46_t_ref, uint16 *) ;
extern int socket_remote46 (int, ip46_t_ref, uint16 *) ;

#define socket_recvnb46(fd, buf, len, i, port, deadline, stamp) ((i)->is6 ? socket_recvnb6(fd, buf, len, (i)->ip, port, deadline, stamp) : socket_recvnb4(fd, buf, len, (i)->ip, port, deadline, stamp))
#define socket_sendnb46(fd, buf, len, i, port, deadline, stamp) ((i)->is6 ? socket_sendnb6(fd, buf, len, (i)->ip, port, deadline, stamp) : socket_sendnb4(fd, buf, len, (i)->ip, port, deadline, stamp))

#else

typedef struct ip46_s ip46_t, *ip46_t_ref ;
struct ip46_s
{
  char ip[4] ;
} ;
#define IP46_ZERO { .ip = "\0\0\0" }

#undef SKALIBS_IPV6_ENABLED
#define SKALIBS_IP_SIZE 4
#define ip46_is6(ip) 0
#define ip46_fmt(s, i) ip4_fmt(s, (i)->ip)
#define ip46_scan(s, i) ip4_scan(s, (i)->ip)
#define ip46_scanlist(out, max, s, num) ip4_scanlist((out)->ip, max, s, num)
#define ip46_from_ip4(i, ip4) (byte_copy((i)->ip, 4, ip4), 1)
#define ip46_from_ip6(i, ip6) (errno = ENOSYS, 0)

#define socket_connect46(s, i, port) socket_connect4(s, (i)->ip, port)
#define socket_bind46(s, i, port) socket_bind4(s, (i)->ip, port)
#define socket_bind46_reuse(s, i, port) socket_bind4_reuse(s, (i)->ip, port)
#define socket_tcp46(h) socket_tcp4()
#define socket_udp46(h) socket_udp4()
#define socket_recv46(fd, s, len, i, port) socket_recv4(fd, s, len, (i)->ip, port)
#define socket_send46(fd, s, len, i, port) socket_send4(fd, s, len, (i)->ip, port)
#define socket_local46(fd, i, port) socket_local4(fd, (i)->ip, port)
#define socket_remote46(fd, i, port) socket_remote4(fd, (i)->ip, port)

#define socket_recvnb46(fd, buf, len, i, port, deadline, stamp) socket_recvnb4(fd, buf, len, (i)->ip, port, deadline, stamp)
#define socket_sendnb46(fd, buf, len, i, port, deadline, stamp) socket_sendnb4(fd, buf, len, (i)->ip, port, deadline, stamp)

#endif

#define ip46_from_ip(i, s, h) ((h) ? ip46_from_ip6(i, s) : ip46_from_ip4(i, s))

#define socket_recvnb46_g(fd, buf, len, i, port, deadline) socket_recvnb46(fd, buf, len, i, port, (deadline), &STAMP)
#define socket_sendnb46_g(fd, buf, len, i, port, deadline) socket_sendnb46(fd, buf, len, i, port, (deadline), &STAMP)

extern int socket_deadlineconnstamp46 (int, ip46_t const *, uint16, struct taia const *, struct taia *) ;
#define socket_deadlineconnstamp46_g(fd, ip, port, deadline) socket_deadlineconnstamp46(fd, ip, port, (deadline), &STAMP)

#endif
