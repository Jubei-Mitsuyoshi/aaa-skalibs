/* ISC license. */

#include "uint32.h"
#include "biguint.h"

int bu_srbc (register uint32 *a, register unsigned int n, register int carry)
{
  while (n--)
  {
    register int c = a[n] & 1 ;
    a[n] = (a[n] >> 1) | (carry ? 0x80000000UL : 0) ;
    carry = c ;
  }
  return carry ;
}
