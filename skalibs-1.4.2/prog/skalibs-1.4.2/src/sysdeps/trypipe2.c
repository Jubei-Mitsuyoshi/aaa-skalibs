/* ISC license. */

#define _GNU_SOURCE
#include <unistd.h>

int main (void)
{
  int p[2] ;
  if (pipe2(p, 0) < 0) return 111 ;
  return 0 ;
}
