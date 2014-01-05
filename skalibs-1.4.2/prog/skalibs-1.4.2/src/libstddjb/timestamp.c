/* ISC license. */

#include "tai.h"

int timestamp (char *s)
{
  struct taia now ;
  return timestamp_r(s, &now) ;
}
