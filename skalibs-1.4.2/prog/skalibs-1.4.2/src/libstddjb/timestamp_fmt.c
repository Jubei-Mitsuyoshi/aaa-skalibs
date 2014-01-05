/* ISC license. */

#include "tai.h"

unsigned int timestamp_fmt (char *s, struct taia const *a)
{
  *s = '@' ;
  return 1 + tain_fmt(s+1, a) ;
}
