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
