/* ISC license. */

#ifndef NONPOSIX_H
#define NONPOSIX_H

 /* Solaris: the socket API is not POSIX unless you enable this */

#ifndef _XPG4_2
# define _XPG4_2
#endif


 /* GNU: most extensions are unavailable unless you enable this */

#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif


 /* BSD: system headers are not self-contained,
      starting with sys/types.h is the usual workaround */

#include <sys/types.h>


 /* FreeBSD: sys/types.h isn't enough, you need nonstandard sys/param.h */

#if defined(__FreeBSD__)
# include <sys/param.h>
#endif

#endif
