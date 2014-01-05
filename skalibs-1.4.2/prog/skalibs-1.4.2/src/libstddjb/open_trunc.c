/* ISC license. */

#include "nonposix.h"
#include <fcntl.h>
#include "djbunix.h"

int open_trunc (char const *fn)
{
  return open3(fn, O_WRONLY | O_NDELAY | O_TRUNC | O_CREAT, 0666) ;
}
