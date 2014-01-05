/* ISC license. */

#include <sys/types.h>
#include <sys/time.h>

int main (void)
{
  hrtime_t t = gethrtime() ;
  return 0 ;
}
