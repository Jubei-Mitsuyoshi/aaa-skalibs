/* ISC license. */

#include "tai.h"

void tai_add (struct tai *t, struct tai const *u, struct tai const *v)
{
  tai_u64(t, tai_sec(u) + tai_sec(v)) ;
}
