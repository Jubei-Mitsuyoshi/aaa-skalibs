/* ISC license. */

#include "uint32.h"
#include "bytestr.h"
#include "surf.h"

#define ROTATE(x, b) (((x) << (b)) | ((x) >> (32 - (b))))
#define MUSH(i, b) x = t[i] += (((x ^ ctx->seed[i]) + sum) ^ ROTATE(x, b))

static void surfit (SURFSchedule_ref ctx)
{
  uint32 t[12] ;
  uint32 z[8] ;
  uint32 x ;
  uint32 sum = 0 ;
  unsigned int i = 0, loop = 0 ; ;

  if (!++ctx->in[0] && !++ctx->in[1] && !++ctx->in[2]) ++ctx->in[3] ;
  for (; i < 12 ; i++) t[i] = ctx->in[i] ^ ctx->seed[12+i] ;
  for (i = 0 ; i < 8 ; i++) z[i] = ctx->seed[24+i] ;
  x = t[11] ;
  for (; loop < 2 ; loop++)
  {
    for (i = 0 ; i < 16 ; i++)
    {
      sum += 0x9e3779b9 ;
      MUSH(0, 5) ; MUSH(1, 7) ; MUSH(2, 9) ;  MUSH(3, 13) ;
      MUSH(4, 5) ; MUSH(5, 7) ; MUSH(6, 9) ;  MUSH(7, 13) ;
      MUSH(8, 5) ; MUSH(9, 7) ; MUSH(10, 9) ; MUSH(11, 13) ;
    }
    for (i = 0 ; i < 8 ; i++) z[i] ^= t[i+4] ;
  }
  for (i = 0 ; i < 8 ; i++) uint32_pack(ctx->out + (i<<2), z[i]) ;
}

void surf (SURFSchedule_ref ctx, char *s, unsigned int n)
{
  {
    register unsigned int i = 32 - ctx->pos ;
    if (n < i) i = n ;
    byte_copy(s, i, ctx->out + ctx->pos) ;
    s += i ; n -= i ; ctx->pos += i ;
  }
  while (n > 32)
  {
    surfit(ctx) ;
    byte_copy(s, 32, ctx->out) ;
    s += 32 ; n -= 32 ;
  }
  if (!n) return ;
  surfit(ctx) ;
  byte_copy(s, n, ctx->out) ;
  ctx->pos = n ;
}
