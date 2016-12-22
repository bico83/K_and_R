/* Exercsise 1-7. Write a program to print the value of EOF */
#include <stdio.h>
typedef unsigned char u8;

void main(void)
{
    int c, res;

    c = getchar();
    while (1) {
        printf("0x%X 0x%X\n", (u8) c >> 8, (u8)c);
        c = getchar();
    }
    /* Never reached */
}
