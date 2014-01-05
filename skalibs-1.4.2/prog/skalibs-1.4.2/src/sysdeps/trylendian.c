/* ISC license. */

#include "hasulong32.h"
#include "hasulong64.h"

int main ()
{
#ifdef HASULONG32

  unsigned long i = 0xdeadbeef ;
  if ((((unsigned char *)(&i))[0] == 0xef)
   && (((unsigned char *)(&i))[1] == 0xbe)
   && (((unsigned char *)(&i))[2] == 0xad)
   && (((unsigned char *)(&i))[3] == 0xde))
    return 0 ;

#else
#ifdef HASULONG64

  unsigned long i = 0x12345678deadbeefUL ;
  if ((((unsigned char *)(&i))[0] == 0xef)
   && (((unsigned char *)(&i))[1] == 0xbe)
   && (((unsigned char *)(&i))[2] == 0xad)
   && (((unsigned char *)(&i))[3] == 0xde)
   && (((unsigned char *)(&i))[4] == 0x78)
   && (((unsigned char *)(&i))[5] == 0x56)
   && (((unsigned char *)(&i))[6] == 0x34)
   && (((unsigned char *)(&i))[7] == 0x12))
    return 0 ;

#endif
#endif

  return 1 ;
}
