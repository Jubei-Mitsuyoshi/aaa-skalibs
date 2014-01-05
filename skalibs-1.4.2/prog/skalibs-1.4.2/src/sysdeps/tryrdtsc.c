/* ISC license. */

int main (void)
{
  unsigned long x[2] = { 0, 0 } ;
  unsigned long y[2] = { 0, 0 } ;

  asm volatile(".byte 15;.byte 49" : "=a"(x[0]),"=d"(x[1]) );
  asm volatile(".byte 15;.byte 49" : "=a"(y[0]),"=d"(y[1]) );

  if (x[0] != y[0]) return 0 ;
  if (x[1] != y[1]) return 0 ;
  return 1 ;
}
