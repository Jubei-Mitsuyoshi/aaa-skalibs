/* ISC license. */

#include <sys/types.h>
#include <sys/stat.h>

int main ()
{
  struct stat st ;
  return (stat("/dev/ptc", &st) == -1) ? 1 : 0 ;
}
