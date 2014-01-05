/* ISC license. */

#ifndef WEBIPC_H
#define WEBIPC_H

 /*
    UNIX domain socket functions.
    "web" stands for William E. Baxter, the original author, who kindly
    permitted me to modify and release his code as a part of skalibs.
    It has nothing to do with the World Wide Web.
 */

#define IPCPATH_MAX 107

#include "tai.h"
#include "djbunix.h"

#define ipc_stream() ipc_stream_nb()
#define ipc_stream_b() ipc_stream_internal(0)
#define ipc_stream_nb() ipc_stream_internal(DJBUNIX_FLAG_NB)
#define ipc_stream_coe() ipc_stream_internal(DJBUNIX_FLAG_COE)
#define ipc_stream_nbcoe() ipc_stream_internal(DJBUNIX_FLAG_NB|DJBUNIX_FLAG_COE)
extern int ipc_stream_internal (unsigned int) ;

#define ipc_datagram() ipc_datagram_nb()
#define ipc_datagram_b() ipc_datagram_internal(0)
#define ipc_datagram_nb() ipc_datagram_internal(DJBUNIX_FLAG_NB)
#define ipc_datagram_coe() ipc_datagram_internal(DJBUNIX_FLAG_COE)
#define ipc_datagram_nbcoe() ipc_datagram_internal(DJBUNIX_FLAG_NB|DJBUNIX_FLAG_COE)
extern int ipc_datagram_internal (unsigned int) ;

extern int ipc_connect (int, char const *) ;
extern int ipc_bind (int, char const *) ;
extern int ipc_bind_reuse (int, char const *) ;
extern int ipc_listen (int, int) ;

#define ipc_accept(s, path, len, trunc) ipc_accept_internal(s, path, len, (trunc), 0)
#define ipc_accept_nb(s, path, len, trunc) ipc_accept_internal(s, path, len, (trunc), DJBUNIX_FLAG_NB)
#define ipc_accept_coe(s, path, len, trunc) ipc_accept_internal(s, path, len, (trunc), DJBUNIX_FLAG_COE)
#define ipc_accept_nbcoe(s, path, len, trunc) ipc_accept_internal(s, path, len, (trunc), DJBUNIX_FLAG_NB|DJBUNIX_FLAG_COE)
extern int ipc_accept_internal (int, char *, unsigned int, int *, unsigned int) ;

extern int ipc_eid (int, unsigned int *, unsigned int *) ;
extern int ipc_local (int, char *, unsigned int, int *) ;

extern int ipc_connect2 (int, char const *) ;
extern int ipc_connected (int) ;
extern int ipc_deadlineconnstamp (int, char const *, struct taia const *, struct taia *) ;
#define ipc_deadlineconnstamp_g(fd, path, deadline) ipc_deadlineconnstamp(fd, path, (deadline), &STAMP)

extern int ipc_send (int, char const *, unsigned int, char const *) ;
extern int ipc_recv (int, char *, unsigned int, char *) ;

#endif
