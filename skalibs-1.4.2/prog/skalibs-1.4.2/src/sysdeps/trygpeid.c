/* ISC license. */

#ifndef _XPG4_2
# define _XPG4_2
#endif

#include <sys/types.h>

#if defined(__FreeBSD__)
# include <sys/param.h>
#endif

#include <sys/socket.h>

int main (void)
{
  int uid ;
  int gid ;
  int s = 0 ;

  return getpeereid(s, &uid, &gid) ;
}
