/* ISC license. */

#include "uint32.h"
#include "sredfa.h"

int sredfa_feed (struct sredfa *p, uint32 *u, char c)
{
  return sredfa_feedn(p, u, &c, 1) ;
}
