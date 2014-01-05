/* ISC license. */

#include "buffer.h"

char *buffer_peek (register buffer_ref b)
{
  return b->x + b->p ;
}
