/* ISC license. */

#include "surf.h"

void surf_autoinit (SURFSchedule_ref ctx, char *s, unsigned int n)
{
  if (!ctx->in[0] && !ctx->in[1] && !ctx->in[2] && !ctx->in[3])
    surf_init(ctx) ;
  surf(ctx, s, n) ;
}
