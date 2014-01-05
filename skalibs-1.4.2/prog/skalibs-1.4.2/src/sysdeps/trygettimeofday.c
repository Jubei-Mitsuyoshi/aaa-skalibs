/* ISC license. */

#include <sys/types.h>
#include <sys/time.h>

int main (void)
{
  struct timeval tv ;
  gettimeofday(&tv, 0) ;
  return 0 ;
}
