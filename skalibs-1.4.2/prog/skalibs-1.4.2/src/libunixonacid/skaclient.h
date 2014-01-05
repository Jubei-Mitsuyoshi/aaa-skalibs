/* ISC license. */

#ifndef _SKACLIENT_H_
#define _SKACLIENT_H_

#include "uint32.h"
#include "stralloc.h"
#include "netstring.h"
#include "tai.h"
#include "bufalloc.h"
#include "buffer.h"
#include "unix-timed.h"

 /* Common client library functions */

 /* skaclientin: common reading interface */

#define SKACLIENTIN_BUFSIZE 4096

typedef int skaclientin_msghandler_t (void *, char const *, unsigned int) ;
typedef skaclientin_msghandler_t *skaclientin_msghandler_t_ref ;

typedef struct skaclientin_s skaclientin_t, *skaclientin_t_ref ;
struct skaclientin_s
{
  buffer b ;
  stralloc data ;
  unsigned int w ;
  char buf[SKACLIENTIN_BUFSIZE] ;
} ;

#define SKACLIENTIN_ZERO { BUFFER_INIT(0, -1, 0, 0), STRALLOC_ZERO, 0, "" }
extern skaclientin_t const skaclientin_zero ;
extern void skaclientin_free (skaclientin_t_ref) ;
extern void skaclientin_end (skaclientin_t_ref) ;
extern void skaclientin_init (skaclientin_t_ref, int) ;

#define skaclientin_fd(in) buffer_fd(&(in)->b)
#define skaclientin_read(in, buf, n, deadline, stamp) timed_buffer_get(&(in)->b, (buf), (n), (deadline), (stamp))
extern int skaclientin_readbanner (skaclientin_t_ref, char const *, unsigned int, struct taia const *, struct taia *) ;
#define skaclientin_readbanner_g(a, banner, bannerlen, deadline) skaclientin_readbanner(a, banner, bannerlen, (deadline), &STAMP)
extern int skaclientin_getack (skaclientin_t_ref, struct taia const *, struct taia *) ;
#define skaclientin_getack_g(a, deadline) skaclientin_getack(a, (deadline), &STAMP)
extern int skaclientin_update (skaclientin_t_ref, skaclientin_msghandler_t_ref, void *) ;


 /* skaclient: standard client with 1 writing fd and 1 reading fd */

typedef struct skaclient_s skaclient_t, *skaclient_t_ref ;
struct skaclient_s
{
  bufalloc out ;
  unsigned int pid ;
  uint32 options ;
  skaclientin_t in ;
} ;

#define SKACLIENT_ZERO { BUFALLOC_ZERO, 0, 0, SKACLIENTIN_ZERO }
extern skaclient_t const skaclient_zero ;
extern void skaclient_free (skaclient_t_ref) ;
#define skaclient_readbanner(a, s, len, deadline, stamp) skaclientin_readbanner(&(a)->in, s, len, deadline, stamp)
#define skaclient_readbanner_g(a, s, len, deadline) skaclient_readbanner(a, s, len, (deadline), &STAMP)

#define SKACLIENT_OPTION_WAITPID 0x00000001U

extern int skaclient_start (skaclient_t_ref, char const *, char const *, unsigned int, struct taia const *, struct taia *) ;
#define skaclient_start_g(a, path, banner, bannerlen, deadline) skaclient_start(a, path, banner, bannerlen, (deadline), &STAMP)
extern int skaclient_startf (skaclient_t_ref, char const *, char const *const *, char const *const *, char const *, unsigned int, uint32, struct taia const *, struct taia *) ;
#define skaclient_startf_g(a, prog, argv, envp, banner, bannerlen, options, deadline) skaclient_startf(a, prog, argv, envp, banner, bannerlen, options, (deadline), &STAMP)
extern void skaclient_end (skaclient_t_ref) ;

#define skaclient_fd(a) skaclientin_fd(&(a)->in)
#define skaclient_pid(a) ((a)->pid)

#define skaclient_put(a, s, n) netstring_putba(&(a)->out, s, n)
#define skaclient_putv(a, v, n) netstring_putbav(&(a)->out, v, n)
#define skaclient_flush(a, deadline, stamp) timed_bufalloc_flush(&(a)->out, deadline, stamp)
#define skaclient_flush_g(a, deadline) skaclient_flush(a, (deadline), &STAMP)
#define skaclient_send(a, s, n, deadline, stamp) (skaclient_put(a, s, n) && skaclient_flush(a, deadline, stamp))
#define skaclient_send_g(a, s, n, deadline) skaclient_send(a, s, n, (deadline), &STAMP)
#define skaclient_sendv(a, v, n, deadline, stamp) (skaclient_putv(a, v, n) && skaclient_flush(a, deadline, stamp))
#define skaclient_sendv_g(a, v, n, deadline) skaclient_sendv(a, v, n, (deadline), &STAMP)
#define skaclient_getack(a, deadline, stamp) skaclientin_getack(&(a)->in, deadline, stamp)
#define skaclient_getack_g(a, deadline) skaclient_getack(a, (deadline), &STAMP)
#define skaclient_getanswer(a, buf, n, deadline, stamp) skaclientin_read(&(a)->in, buf, n, deadline, stamp)
#define skaclient_getanswer_g(a, buf, n, deadline) skaclient_getanswer(a, buf, n, (deadline), &STAMP)
#define skaclient_update(a, f, p) skaclientin_update(&(a)->in, f, p)


 /* skaclient2: client with a sync 2-way IPC plus a 1-way async pipe from the server to the client */

typedef struct skaclient2_s skaclient2_t, *skaclient2_t_ref ;
struct skaclient2_s
{
  skaclient_t sync ;
  skaclientin_t async ;
} ;

#define SKACLIENT2_ZERO { SKACLIENT_ZERO, SKACLIENTIN_ZERO }
extern skaclient2_t const skaclient2_zero ;

extern void skaclient2_free (skaclient2_t_ref) ;
extern int skaclient2_start (skaclient2_t_ref, char const *, char const *, unsigned int, char const *, unsigned int, struct taia const *, struct taia *) ;
#define skaclient2_start_g(a, path, before, beforelen, after, afterlen, deadline) skaclient2_start(a, path, before, beforelen, after, afterlen, (deadline), &STAMP)
extern int skaclient2_startf (skaclient2_t_ref, char const *, char const *const *, char const *const *, char const *, unsigned int, char const *, unsigned int, uint32, struct taia const *, struct taia *) ;
#define skaclient2_startf_g(a, prog, argv, envp, before, beforelen, after, afterlen, options, deadline) skaclient2_startf(a, prog, argv, envp, before, beforelen, after, afterlen, options, (deadline), &STAMP)
extern void skaclient2_end (skaclient2_t_ref) ;

#define skaclient2_fd(a) skaclientin_fd(&(a)->async)
#define skaclient2_pid(a) skaclient_pid(&(a)->sync)
#define skaclient2_put(a, s, n) skaclient_put(&(a)->sync, s, n)
#define skaclient2_putv(a, v, n) skaclient_putv(&(a)->sync, v, n)
#define skaclient2_flush(a, deadline, stamp) skaclient_flush(&(a)->sync, deadline, stamp)
#define skaclient2_flush_g(a, deadline) skaclient2_flush(a, (deadline), &STAMP)
#define skaclient2_send(a, s, n, deadline, stamp) skaclient_send(&(a)->sync, s, n, deadline, stamp)
#define skaclient2_send_g(a, s, n, deadline) skaclient2_send(a, s, n, (deadline), &STAMP)
#define skaclient2_sendv(a, v, n, deadline, stamp) skaclient_sendv(&(a)->sync, v, n, deadline, stamp)
#define skaclient2_sendv_g(a, v, n, deadline) skaclient2_sendv(a, v, n, (deadline), &STAMP)
#define skaclient2_getack(a, deadline, stamp) skaclient_getack(&(a)->sync, deadline, stamp)
#define skaclient2_getack_g(a, deadline) skaclient2_getack(a, (deadline), &STAMP)
#define skaclient2_getanswer(a, buf, n, deadline, stamp) skaclient_getanswer(&(a)->sync, buf, n, deadline, stamp)
#define skaclient2_getanswer_g(a, buf, n, deadline) skaclient2_getanswer(a, buf, n, (deadline), &STAMP)
#define skaclient2_update(a, f, p) skaclientin_update(&(a)->async, f, p)

extern int skaserver2_sync (bufalloc *, char const *, unsigned int, char const *, unsigned int, struct taia const *, struct taia *) ;
#define skaserver2_sync_g(ba, before, beforelen, after, afterlen, deadline) skaserver2_sync(ba, before, beforelen, after, afterlen, (deadline), &STAMP)

#endif
