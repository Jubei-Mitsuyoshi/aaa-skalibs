/* ISC license. */

#include "buffer.h"

int buffer_putallflush (buffer_ref b, char const *buf, unsigned int len, unsigned int *written)
{
  return (buffer_putall(b, buf, len, written) == -1) ? -1 : buffer_flush(b) ;
}
