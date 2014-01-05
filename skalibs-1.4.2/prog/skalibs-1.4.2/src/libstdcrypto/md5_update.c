/* ISC license. */

#include "uint32.h"
#include "bytestr.h"
#include "md5.h"
#include "md5-internal.h"

void md5_update (MD5Schedule_ref ctx, char const *s, unsigned int len)
{
  register uint32 t = ctx->bits[0] ;
  if ((ctx->bits[0] = t + (len << 3)) < t)
    ctx->bits[1]++ ;
  ctx->bits[1] += len >> 29 ;
  t = (t >> 3) & 0x3f ;
  if (t)
  {
    unsigned char *p = ctx->in + t ;
    t = 64 - t ;
    if (len < t)
    {
      byte_copy((char *)p, len, s) ;
      return ;
    }
    byte_copy((char *)p, t, s) ;
    uint32_little_endian(ctx->in, 16) ;
    md5_transform(ctx->buf, (uint32 *)ctx->in) ;
    s += t ; len -= t ;
  }
  while (len >= 64)
  {
    byte_copy((char *)ctx->in, 64, s) ;
    uint32_little_endian(ctx->in, 16) ;
    md5_transform(ctx->buf, (uint32 *)ctx->in) ;
    s += 64 ; len -= 64 ;
  }
  byte_copy((char *)ctx->in, len, s) ;
}
