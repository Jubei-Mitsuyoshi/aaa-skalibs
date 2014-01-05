/* ISC license. */

#ifndef TAI_H
#define TAI_H

#include <sys/types.h>
#include <time.h>
#include <sys/time.h>
#include "gccattributes.h"
#include "uint32.h"
#include "uint64.h"

struct tai
{
  uint64 x ;
} ;


#define TAI_ZERO { 0 }
#define TAI_MAGIC ((uint64)4611686018427387904ULL)
#define TAI_EPOCH { TAI_MAGIC + 10UL }
#define TAI_INFINITE_RELATIVE { ((uint64)0x0100000000000000ULL) }
#define TAI_INFINITE { TAI_MAGIC + ((uint64)0x0100000000000000ULL) }

#define tai_sec(t) ((t)->x)
#define tai_u64(t, u) ((void)((t)->x = (u)))
#define tai_unix(t, u) tai_u64(t, (TAI_MAGIC + (u)))
#define tai_uint(t, u) tai_u64(t, (uint64)(u))

extern int tai_relative_from_timeval (struct tai *, struct timeval const *) ;
extern int tai_from_timeval (struct tai *, struct timeval const *) ;
extern int timeval_from_tai_relative (struct timeval *, struct tai const *) ;
extern int timeval_from_tai (struct timeval *, struct tai const *) ;

extern int tai_relative_from_timespec (struct tai *, struct timespec const *) ;
extern int tai_from_timespec (struct tai *, struct timespec const *) ;
extern int timespec_from_tai_relative (struct timespec *, struct tai const *) ;
extern int timespec_from_tai (struct timespec *, struct tai const *) ;

extern int tai_now (struct tai *) ;
extern int tai_from_sysclock (struct tai *, uint64) ;
extern int sysclock_from_tai (uint64 *, struct tai const *) ;

#define tai_approx(t) ((double)(tai_sec(t)))

extern void tai_add (struct tai *, struct tai const *, struct tai const *) ;
extern void tai_sub (struct tai *, struct tai const *, struct tai const *) ;
#define tai_less(t,u) (tai_sec(t) < tai_sec(u))

#define TAI_PACK 8
extern void tai_pack (char *, struct tai const *) ;
extern void tai_unpack (char const *, struct tai *) ;
extern void tai_pack_little (char *, struct tai const *) ;
extern void tai_unpack_little (char const *, struct tai *) ;

struct taia
{
  struct tai sec ;
  uint32 nano ; /* 0..999999999 */
  uint32 atto ; /* 0..999999999 */
} ;

#define TAIA_ZERO { TAI_ZERO, 0, 0 }
#define TAIA_EPOCH { TAI_EPOCH, 0, 0 }
#define TAIA_INFINITE { TAI_INFINITE, 0, 0 }
#define TAIA_INFINITE_RELATIVE { TAI_INFINITE_RELATIVE, 0, 0 }
#define TAIA_NANO500 { TAI_ZERO, 500U, 0 }

extern struct taia STAMP ; /* the global process wallclock */
extern struct taia const infinitetto ;
extern struct taia const taia_nano500 ;

extern void taia_tai (struct taia const *, struct tai *) ;

#define taia_sec(a) ((a)->sec)
#define taia_secp(a) (&(a)->sec)
#define taia_nano(a) ((a)->nano)
#define taia_atto(a) ((a)->atto)

extern int taia_relative_from_timeval (struct taia *, struct timeval const *) ;
extern int taia_from_timeval (struct taia *, struct timeval const *) ;
extern int timeval_from_taia_relative (struct timeval *, struct taia const *) ;
extern int timeval_from_taia (struct timeval *, struct taia const *) ;

extern int taia_relative_from_timespec (struct taia *, struct timespec const *) ;
extern int taia_from_timespec (struct taia *, struct timespec const *) ;
extern int timespec_from_taia_relative (struct timespec *, struct taia const *) ;
extern int timespec_from_taia (struct timespec *, struct taia const *) ;

extern int sysclock_get (struct taia *) ;
extern int taia_sysclock (struct taia *) ;
#define taia_sysclock_g() taia_sysclock(&STAMP)
extern int taia_clockmon_init (struct taia *) ;
extern int taia_clockmon (struct taia *, struct taia const *) ;
#define taia_clockmon_g(offset) taia_clockmon(&STAMP, (offset))
extern int taia_init (void) ;
extern int taia_now (struct taia *) ;
#define taia_now_g() taia_now(&STAMP)
#define taia_copynow(t) (*(t) = STAMP)

extern int sysclock_set (struct taia const *) ;
extern int taia_setnow (struct taia const *) ;

extern double taia_approx (struct taia const *) gccattr_pure ;
extern double taia_frac (struct taia const *) gccattr_pure ;

extern int taia_from_millisecs (struct taia *, int) ;
extern int taia_to_millisecs (struct taia const *) gccattr_pure ;

extern void taia_add (struct taia *, struct taia const *, struct taia const *) ;
#define taia_add_g(deadline, tto) taia_add(deadline, &STAMP, tto)
extern void taia_addsec (struct taia *, struct taia const *, int) ;
#define taia_addsec_g(deadline, n) taia_addsec(deadline, &STAMP, n)
extern void taia_sub (struct taia *, struct taia const *, struct taia const *) ;
extern void taia_half (struct taia *, struct taia const *) ;
extern int taia_less (struct taia const *, struct taia const *) gccattr_pure ;
#define taia_future(deadline) taia_less(&STAMP, (deadline))

#define TAIA_PACK 16
extern void taia_pack (char *, struct taia const *) ;
extern void taia_unpack (char const *, struct taia *) ;
extern void taia_pack_little (char *, struct taia const *) ;
extern void taia_unpack_little (char const *, struct taia *) ;

#define TAIA_FMT 33
extern unsigned int taia_fmt (char *, struct taia const *) ;
extern unsigned int taia_scan (char const *, struct taia *) ;

#define TAIN_PACK 12
extern void tain_pack (char *, struct taia const *) ;
extern void tain_unpack (char const *, struct taia *) ;
extern void tain_pack_little (char *, struct taia const *) ;
extern void tain_unpack_little (char const *, struct taia *) ;

#define TAIN_FMT 25
extern unsigned int tain_fmt (char *, struct taia const *) ;
extern unsigned int tain_scan (char const *, struct taia *) ;

#define TAIA_FMTFRAC 19
extern unsigned int taia_fmtfrac (char *, struct taia const *) ;

#define taia_uint(a, u) taia_ulong(a, u)
extern void taia_ulong (struct taia *, unsigned long) ;

#define TIMESTAMP (1 + (TAIN_PACK << 1))
extern unsigned int timestamp_fmt (char *, struct taia const *) ;
extern unsigned int timestamp_scan (char const *, struct taia *) ;
extern int timestamp_r (char *, struct taia *) ;
extern int timestamp (char *) ;
#define timestamp_g(s) timestamp_fmt((s), &STAMP)

#endif
