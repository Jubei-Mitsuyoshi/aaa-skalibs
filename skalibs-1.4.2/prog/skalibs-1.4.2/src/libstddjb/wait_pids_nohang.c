/* ISC license. */

#include "djbunix.h"

int wait_pids_nohang (int *wstat, unsigned int const *pids, unsigned int len)
{
  for (;;)
  {
    int w ;
    register int r = wait_nohang(&w) ;
    if (r <= 0) return r ;
    {
      register unsigned int i = 0 ;
      for (; i < len ; i++)
        if ((unsigned int)r == pids[i])
        {
          *wstat = w ;
          return 1+i ;
        }
    }
  }
}
