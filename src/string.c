#include "string.h"

int strlen(char *c)
{
    int i=0;
    while (c[i])
    {
        i++;
    }
    return i;
}

void strcpy(char *a,char *b,int start,int num)
{
 int len = strlen(a),len2=strlen(b),i,j=0;
 if ((start+num<=len2 )&& (num>=0)&& (start>=0))
    {
        if (num!=0)
            len = num;
        for (i=start;i<len;i++,j++)        
            b[j]=a[i];                   
    }
}

unsigned char* memcpy (unsigned char *dest, const unsigned char * src, int count)
{
  int i;
  for(i=0; i<count; i++) 
        dest[i]=src[i];
  return dest;
}

unsigned char* memset (unsigned char *dest, unsigned char val,int count)
{
  int i;
  for(i=0; i<count; i++) 
        dest[i]=val;
  return dest;
}

