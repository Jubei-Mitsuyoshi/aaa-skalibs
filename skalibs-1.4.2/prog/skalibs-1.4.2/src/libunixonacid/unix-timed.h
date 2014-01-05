/* ISC license. */

#ifndef _UNIX_TIMED_H_
#define _UNIX_TIMED_H_

#include "tai.h"
#include "stralloc.h"
#include "bufalloc.h"
#include "buffer.h"

 /* Timed "blocking" operations (the fd must still be non-blocking) */

extern int timed_buffer_fill (buffer_ref, struct taia const *, struct taia *) ;
#define timed_buffer_fill_g(b, deadline) timed_buffer_fill(b, (deadline), &STAMP)
extern int timed_bufalloc_flush (bufalloc_ref, struct taia const *, struct taia *) ;
#define timed_bufalloc_flush_g(ba, deadline) timed_bufalloc_flush(ba, (deadline), &STAMP)
extern int timed_buffer_flush (buffer_ref, struct taia const *, struct taia *) ;
#define timed_buffer_flush_g(b, deadline) timed_buffer_flush(b, (deadline), &STAMP)
extern unsigned int timed_buffer_get (buffer_ref, char *, unsigned int, struct taia const *, struct taia *) ;
#define timed_buffer_get_g(b, buf, buflen, deadline) timed_buffer_get(b, buf, buflen, (deadline), &STAMP)
extern int timed_getln (buffer_ref, stralloc *, int, struct taia const *, struct taia *) ;
#define timed_getln_g(b, sa, ok, deadline) timed_getln(b, sa, ok, (deadline), &STAMP)
extern int timed_getlnmax (buffer_ref, char *, unsigned int, unsigned int *, int, struct taia const *, struct taia *) ;
#define timed_getlnmax_g(b, max, maxlen, len, ok, deadline) timed_getlnmax(b, max, maxlen, len, ok, (deadline), &STAMP)
extern int timed_fd_read1 (int, char *, struct taia const *, struct taia *) ;
#define timed_fd_read1_g(fd, c, deadline) timed_fd_read1(fd, c, (deadline), &STAMP)
extern int timed_protocol_answer (int, struct taia const *, struct taia *) ;
#define timed_protocol_answer_g(fd, deadline) timed_protocol_answer(fd, (deadline), &STAMP)

extern int timed_ancil_fd_recv (int, int *, struct taia const *, struct taia *) ;
#define timed_ancil_fd_recv_g(fd, r, deadline) timed_ancil_fd_recv(fd, r, (deadline), &STAMP)
extern int timed_ancil_fd_send (int, int, struct taia const *, struct taia *) ;
#define timed_ancil_fd_send_g(fd, w, deadline) timed_ancil_fd_send(fd, w, (deadline), &STAMP)
extern int timed_ancil_fd_sandwiched_recv (int, char const *, unsigned int, char const *, unsigned int, struct taia const *, struct taia *) ;
#define timed_ancil_fd_sandwiched_recv_g(fd, before, beforelen, after, afterlen, deadline) timed_ancil_fd_sandwiched_recv(fd, before, beforelen, after, afterlen, (deadline), &STAMP)

#endif
