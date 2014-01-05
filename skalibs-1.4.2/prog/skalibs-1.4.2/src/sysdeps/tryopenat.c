/* ISC license. */

#define _GNU_SOURCE
#include <sys/stat.h>
#include <fcntl.h>

int main (void)
{
  int fd = openat(0, "/", O_RDONLY) ;
  return (fd < 0) ;
}
