/* ISC license. */

#include "djbunix.h"

int waitn_reap (unsigned int *pids, unsigned int len)
{
  unsigned int n = 0 ;
  while (len)
  {
    int w ;
    register int r = wait_pids_nohang(&w, pids, len) ;
    if (r < 0) return r ;
    else if (!r) break ;
    pids[r-1] = pids[--len] ;
    n++ ;
  }
  return n ;
}
