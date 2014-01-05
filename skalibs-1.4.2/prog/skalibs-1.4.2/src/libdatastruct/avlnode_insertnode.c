/* ISC license. */

#include "functypes.h"
#include "avlnode.h"
#include "avlnode-internal.h"

unsigned int avlnode_insertnode (avlnode_ref s, unsigned int max, unsigned int r, unsigned int i, uintcmpfunc_t_ref f, void *p)
{
  unsigned int stack[AVLNODE_MAXDEPTH] ;
  int spin[AVLNODE_MAXDEPTH] ;
  unsigned int sp = 0 ;
  
  {
    register unsigned int k = s[i].data ;
    for (; r < max ; sp++)
    {
      spin[sp] = avlnode_ufroms((*f)(k, s[r].data, p)) ;
      stack[sp] = r ;
      r = s[r].child[spin[sp]] ;
    }
  }
  r = i ;
  while (sp--)
  {
    s[stack[sp]].child[spin[sp]] = r ;
    r = stack[sp] ;
    if (s[r].balance) goto lastfix ;
    s[r].balance = avlnode_sfromu(spin[sp]) ;
  }
  return r ;

 lastfix:
  if (avlnode_ufroms(s[r].balance) != spin[sp])
  {
    s[r].balance = 0 ;
    return stack[0] ;
  }
  r = avlnode_rotate_maydouble(s, max, r, !spin[sp], spin[sp] != spin[sp+1]) ;
  if (!sp--) return r ;
  s[stack[sp]].child[spin[sp]] = r ;
  return stack[0] ;
}
