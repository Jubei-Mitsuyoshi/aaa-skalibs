/* ISC license. */

#include "functypes.h"
#include "avlnode.h"
#include "avlnode-internal.h"

unsigned int avlnode_delete (avlnode_ref s, unsigned int max, unsigned int *root, unsigned int k, uintcmpfunc_t_ref f, void *p)
{
  unsigned int stack[AVLNODE_MAXDEPTH] ;
  int spin[AVLNODE_MAXDEPTH] ;
  unsigned int sp = 0 ;
  unsigned int r = *root ;

  for (; r < max ; sp++)
  {
    register int c = (*f)(k, s[r].data, p) ;
    if (!c) break ;
    spin[sp] = avlnode_ufroms(c) ;
    stack[sp] = r ;
    r = s[r].child[spin[sp]] ;
  }
  if (r >= max) return max ;
  k = r ;

  if ((s[r].child[0] < max) || (s[r].child[1] < max))
  {
    int subspin = s[r].child[1] < max ;
    stack[sp] = r ;
    spin[sp++] = subspin ;
    r = s[r].child[subspin] ;
    for (; r < max ; sp++)
    {
      stack[sp] = r ;
      spin[sp] = !subspin ;
      r = s[r].child[!subspin] ;
    }
    r = stack[--sp] ;
    s[k].data = s[r].data ;
    k = s[r].child[subspin] ;
    if (k < max)
    {
      s[r].data = s[k].data ;
      stack[sp] = r ;
      spin[sp++] = subspin ;
    }
    else k = r ;
  }

  r = max ; 
  while (sp--)
  {
    s[stack[sp]].child[spin[sp]] = r ;
    r = stack[sp] ;
    if (!s[r].balance) goto easyfix ;
    else if (spin[sp] == avlnode_ufroms(s[r].balance)) s[r].balance = 0 ;
    else if (!s[s[r].child[!spin[sp]]].balance) goto hardfix ;
    else r = avlnode_rotate_maydouble(s, max, r, spin[sp], spin[sp] == avlnode_ufroms(s[s[r].child[!spin[sp]]].balance)) ;
  }
  *root = r ;
  return k ;

 easyfix:
  s[r].balance = -avlnode_sfromu(spin[sp]) ;
  return k ;

 hardfix:
  r = avlnode_rotate(s, max, r, spin[sp]) ;
  if (!sp--) *root = r ;
  else s[stack[sp]].child[spin[sp]] = r ;
  return k ;
}
