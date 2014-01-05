/* ISC license. */

#include <sys/time.h>
#include <errno.h>
#include "tai.h"

int timeval_from_taia_relative (struct timeval *tv, struct taia const *a)
{
  struct timeval tmp ;
  if (!timeval_from_tai_relative(&tmp, taia_secp(a)))
    return (errno = EINVAL, 0) ;
  tv->tv_sec = tmp.tv_sec ;
  tv->tv_usec = a->nano / 1000 ;
  return 1 ;
}
