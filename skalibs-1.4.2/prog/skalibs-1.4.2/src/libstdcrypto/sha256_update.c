/* ISC license. */

#include "sha256.h"
#include "sha256-internal.h"

void sha256_update (SHA256Schedule_ref ctx, char const *buf, unsigned int len)
{
  register unsigned int i = 0 ;
  for (; i < len ; i++) sha256_feed(ctx, (unsigned char)buf[i]) ;
}
