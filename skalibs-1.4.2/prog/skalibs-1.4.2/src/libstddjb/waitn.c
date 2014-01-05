/* ISC license. */

#include <sys/wait.h>
#include "djbunix.h"

int waitn (unsigned int *pids, unsigned int n)
{
  while (n)
  {
    int wstat ;
    register unsigned int i = 0 ;
    register int pid = wait(&wstat) ;
    if (pid < 0) return 0 ;
    for (; i < n ; i++) if ((unsigned int)pid == pids[i]) break ;
    if (i < n) pids[i] = pids[--n] ;
  }
  return 1 ;
}
