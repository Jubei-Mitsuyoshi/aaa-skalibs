/* ISC license. */

#ifndef CDB_MAKE_H
#define CDB_MAKE_H

#include "allreadwrite.h"
#include "uint32.h"
#include "diuint32.h"
#include "genalloc.h"
#include "buffer.h"

typedef struct cdb_make cdb_make, *cdb_make_ref ;
struct cdb_make
{
  char buf[BUFFER_OUTSIZE] ;
  genalloc hplist ; /* diuint32 */
  buffer b ;
  uint32 pos ;
  int fd ;
} ;

#define CDB_MAKE_ZERO { "", GENALLOC_ZERO, BUFFER_INIT((iofunc_t_ref)&fd_write, -1, 0, 0), 2048, -1 }

extern int cdb_make_start (struct cdb_make *, int) ;
extern int cdb_make_add (struct cdb_make *, char const *, unsigned int, char const *, unsigned int) ;
extern int cdb_make_finish (struct cdb_make *) ;

#endif
