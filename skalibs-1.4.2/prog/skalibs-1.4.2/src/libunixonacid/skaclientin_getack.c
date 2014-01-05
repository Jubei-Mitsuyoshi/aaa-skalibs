/* ISC license. */

#include <errno.h>
#include "buffer.h"
#include "tai.h"
#include "unix-timed.h"
#include "skaclient.h"

int skaclientin_getack (skaclientin_t_ref in, struct taia const *deadline, struct taia *stamp)
{
  char c ;
  return buffer_getnofill(&in->b, &c, 1) ? c ? (errno = c, 0) : 1 : timed_protocol_answer(in->b.fd, deadline, stamp) ;
}
