#include "stdlib.h"

void itoa (char *buf, int base, int d)
{
   char *p = buf,*p1,*p2;
   unsigned long nd = d;
   int divisor = 10;
  
  /* If %d is specified and D is minus, put `-' in the head.  */
  if (base == 'd' && d < 0)
    {
      *p++ = '-';
      buf++;
      nd = -d;
    }
  else if (base == 'x')
    divisor = 16;

  /* Divide nd by divisor until nd is 0.  */
  do
    {
      int remainder = nd % divisor;
      
      *p++ = (remainder < 10) ? remainder + '0' : remainder + 'a' - 10;
    }
  while (nd /= divisor);

  /* Terminate BUF.  */
  *p = 0;
  
  /* Reverse BUF.  */
  p1 = buf;
  p2 = p - 1;
  while (p1 < p2)
    {
      char tmp = *p1;
      *p1 = *p2;
      *p2 = tmp;
      p1++;
      p2--;
    }
}


