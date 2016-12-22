/* Exercise 1-12. Write a program that prints its input one word per line */
#include <stdio.h>

#define IN 1
#define OUT 0

void main(void)
{
    char c;
    int state;

    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            printf("\n");    
            printf("%c",c);    
        }
        else 
            printf("%c",c);    
    }
}
