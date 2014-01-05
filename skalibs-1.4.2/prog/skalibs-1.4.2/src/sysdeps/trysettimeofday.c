/* ISC license. */

#define _BSD_SOURCE
#include <sys/types.h>
#include <sys/time.h>

int main (void)
{
  struct timeval tv ;
  gettimeofday(&tv, 0) ;
  settimeofday(&tv, 0) ;
  return 0 ;
}
