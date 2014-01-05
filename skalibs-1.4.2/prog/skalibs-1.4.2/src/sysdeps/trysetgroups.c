/* ISC license. */

#define _BSD_SOURCE
#include <sys/types.h>
#include <unistd.h>
#include <grp.h>

int main (void)
{
  gid_t g = 0 ;
  setgroups(1, &g) ;
  return 0 ;
}
