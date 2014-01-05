/* ISC license. */

#include <sys/types.h>
#include <sys/stat.h>

int main ()
{
  return mkfifo("temp-trymkffo", 0) ;
}
