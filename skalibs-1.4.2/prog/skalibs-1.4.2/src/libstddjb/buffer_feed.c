/* ISC license. */

#include "buffer.h"

int buffer_feed (register buffer_ref b)
{
  return (b->n > b->p) ? ((int)b->n - (int)b->p) : buffer_fill(b) ;
}
