/* ISC license. */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main ()
{
  int fd ;
  char *name = _getpty(&fd, O_RDWR, 0600, 0) ;
  return 0 ;
}
