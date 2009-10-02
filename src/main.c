#include "screen.h"
#include "string.h"

int main()
{
    clear();
    puts("Welcome To TIK \n");
    putsxy("At (5,10)",5,10);
    puts("Now Back:");
    char *a ="cat";
    char *b ="lolpack";
    strcpy(a,b,0,3);
    puts(b);
    return 0;
}
