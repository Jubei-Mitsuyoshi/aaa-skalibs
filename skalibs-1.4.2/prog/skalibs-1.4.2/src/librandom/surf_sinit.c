/* ISC license. */

#include "uint32.h"
#include "surf.h"

void surf_sinit (SURFSchedule_ref ctx, char const *s)
{
  SURFSchedule zero = SURFSCHEDULE_ZERO ;
  register unsigned int i = 4 ;
  *ctx = zero ;
  for (; i < 12 ; i++) uint32_unpack(s + (i<<2) - 16, ctx->in + i) ;
  for (i = 0 ; i < 32 ; i++) uint32_unpack(s + 32 + (i<<2), ctx->seed + i) ;
}
