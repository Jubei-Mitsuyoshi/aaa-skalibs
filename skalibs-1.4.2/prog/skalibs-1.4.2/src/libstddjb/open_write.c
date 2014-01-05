/* ISC license. */

#include "nonposix.h"
#include <fcntl.h>
#include "djbunix.h"

int open_write (char const *fn)
{
  return open2(fn, O_WRONLY | O_NDELAY) ;
}
