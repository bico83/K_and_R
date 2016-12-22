/* Exercise 1-9. Write a program to copy its input to its output, replacing
 * each string of one or more blanks by a single blank. 
 */
#include <stdio.h>

void main(void)
{
    char c, last_c;

    last_c = 'X';

    while ((c = getchar()) != EOF) {
        if (c == ' ' && last_c == ' ')
            ;/* Do nothing */ 
        else
            printf("%c",c);
        last_c = c;
    }
}
