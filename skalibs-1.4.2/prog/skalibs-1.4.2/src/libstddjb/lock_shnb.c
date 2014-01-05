/* ISC license. */

#include <unistd.h>
#include <sys/types.h>
#include <sys/file.h>
#include <fcntl.h>
#include "sysdeps.h"
#include "djbunix.h"

#ifdef HASFLOCK
int lock_shnb (int fd) { return flock(fd, LOCK_SH | LOCK_NB) ; }
#else
int lock_shnb (int fd) { return lockf(fd, 2, 0) ; }
#endif
