/* ISC license. */

#include "tai.h"
#include "iopause.h"

extern int iopause_stamp (iopause_fd *x, unsigned int n, struct taia const *deadline, struct taia *stamp)
{
  register int r = iopause(x, n, deadline, stamp) ;
  if (stamp) taia_now(stamp) ;
  return r ;
}
