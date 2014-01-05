/* ISC license. */

#include <sys/types.h>

#include "hasptyh.h"
#ifdef HASPTYH
#include <pty.h>
#endif

#include "hasutilh.h"
#ifdef HASUTILH
#include <util.h>
#endif

#include "haslibutilh.h"
#ifdef HASLIBUTILH
#include <libutil.h>
#endif

int main ()
{
  int fd[2] ;
  openpty(&fd[0], &fd[1], 0, 0, 0) ;
  return 0 ;
}
