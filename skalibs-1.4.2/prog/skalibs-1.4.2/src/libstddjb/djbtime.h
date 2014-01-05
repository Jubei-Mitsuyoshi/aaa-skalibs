/* ISC license. */

#ifndef DJBTIME_H
#define DJBTIME_H

#include <time.h>
#include "skalibs-config.h"
#include "uint32.h"
#include "uint64.h"
#include "tai.h"

#define NTP_OFFSET 2208988800UL
#define NTP_MAGIC_FRAC 232830644UL  /* 10^18/2^32 */


/* Leap second handling, for UTC <--> TAI conversions */

#define LEAPSECS_MAX 39
#define LEAPSECS_FILE SKALIBS_ETC "/leapsecs.dat"
extern uint64 *leapsecs_here ;

extern int leapsecs_init_r (char const *, uint64 *) ;
#define leapsecs_init() leapsecs_init_r(LEAPSECS_FILE, leapsecs_here)
extern int leapsecs_add_r (uint64 *, char const *, uint64 *, int) ;
#define leapsecs_add(t, h) leapsecs_add_r(t, LEAPSECS_FILE, leapsecs_here, h)
extern int leapsecs_sub_r (uint64 *, char const *, uint64 *) ;
#define leapsecs_sub(t) leapsecs_sub_r((t), LEAPSECS_FILE, leapsecs_here)


/* UTC <--> TAI conversions */
/* sysclock can be either TAI-10 or UTC depending on flag-clockistai */

extern int utc_from_tai (uint64 *, struct tai const *) ;
extern int tai_from_utc (struct tai *, uint64) ;
extern int utc_from_sysclock (uint64 *) ;
extern int sysclock_from_utc (uint64 *) ;


/* NTP internal format */

extern int ntp_from_taia (uint64 *, struct taia const *) ;
extern int taia_from_ntp (struct taia *, uint64) ;


/* localtime handling - replaces caltimedate functions */
/* ltm64 can be either TAI-10 or UTC depending on flag-tzisright */
/* normally ltm64 is the same as sysclock, but we allow it to be different */
/* for instance for uClibc TAI-10 systems */

typedef struct localtmn_s localtmn_t, *localtmn_t_ref ;
struct localtmn_s
{
  struct tm tm ;
  uint32 nano ;
} ;

extern int ltm64_from_tai (uint64 *, struct tai const *) ;
extern int tai_from_ltm64 (struct tai *, uint64) ;
extern int ltm64_from_utc (uint64 *) ;
extern int utc_from_ltm64 (uint64 *) ;
extern int ltm64_from_sysclock (uint64 *) ;
extern int sysclock_from_ltm64 (uint64 *) ;

extern int localtm_from_ltm64 (struct tm *, uint64, int) ;
extern int ltm64_from_localtm (uint64 *, struct tm const *) ;
extern int localtm_from_sysclock (struct tm *, uint64, int) ;
extern int sysclock_from_localtm (uint64 *, struct tm const *) ;
extern int localtm_from_utc (struct tm *, uint64, int) ;
extern int utc_from_localtm (uint64 *, struct tm const *) ;
extern int localtm_from_tai (struct tm *, struct tai const *, int) ;
extern int tai_from_localtm (struct tai *, struct tm const *) ;

extern int localtmn_from_taia (localtmn_t_ref, struct taia const *, int) ;
extern int taia_from_localtmn (struct taia *, localtmn_t const *) ;
extern int localtmn_from_sysclock (localtmn_t_ref, struct taia const *, int) ;
extern int sysclock_from_localtmn (struct taia *, localtmn_t const *) ;

#define LOCALTM_FMT 21
extern unsigned int localtm_fmt (char *, struct tm const *) ;
extern unsigned int localtm_scan (char const *, struct tm *) ;

#define LOCALTMN_FMT 31
extern unsigned int localtmn_fmt (char *, localtmn_t const *) ;
extern unsigned int localtmn_scan (char const *, localtmn_t_ref) ;

#endif
