/* ISC license. */

#include "nonposix.h"
#include <fcntl.h>
#include "djbunix.h"

int open_append (char const *fn)
{
  return open3(fn, O_WRONLY | O_NDELAY | O_APPEND | O_CREAT, 0666) ;
}
