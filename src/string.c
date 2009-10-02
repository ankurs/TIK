// To count charachters in the string
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

// To copy from string a to string b for given length stating from start, for l=0  complete string is copied

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
