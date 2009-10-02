#include "screen.h"
#include "string.h"

int main()
{
    clear();
    puts("Welcome To TIK \n");
    putsxy("At (5,10)",5,10);
    puts("Now Back:");
    put(strlen("cat"));
    return 0;
}
