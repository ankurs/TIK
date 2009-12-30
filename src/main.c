#include "screen.h"
#include "string.h"

int main()
{
    clear();
    char txt[6]="World";
    printf("Hello World\n");
    init_descriptor_tables();
    // testing interrupt
    asm volatile ("int $0x3");
    asm volatile ("int $0x4");
    printf("bye bye world");
    return 0;
}
