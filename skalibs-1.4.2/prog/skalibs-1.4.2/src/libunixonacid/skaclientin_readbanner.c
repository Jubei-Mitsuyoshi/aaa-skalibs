/* ISC license. */

#include <errno.h>
#include "error.h"
#include "bytestr.h"
#include "tai.h"
#include "unix-timed.h"
#include "skaclient.h"

int skaclientin_readbanner (skaclientin_t_ref in, char const *banner, unsigned int bannerlen, struct taia const *deadline, struct taia *stamp)
{
  register unsigned int i = 0 ;
  for (; i < bannerlen ; i++)
  {
    char c ;
    if (timed_buffer_get(&in->b, &c, 1, deadline, stamp) < 1) return 0 ;
    if (c != banner[i]) return (errno = EPROTO, 0) ;
  }
  return 1 ;
}
