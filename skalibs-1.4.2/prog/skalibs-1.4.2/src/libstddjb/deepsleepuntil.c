/* ISC license. */

#include "tai.h"
#include "iopause.h"

void deepsleepuntil (struct taia const *deadline, struct taia *stamp)
{
  iopause_fd x ;
  while (taia_less(stamp, deadline)) iopause_stamp(&x, 0, deadline, stamp) ;
}
