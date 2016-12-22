/* Exercise 1-14. Write a program to print a histogram of the frequencies
 * of different characters in its input.
 */
#include <stdio.h>

void main(void)
{
    char c;
    int digits_array[10], blank_count, other_count, i, j;

    for (i = 0; i < 10; ++i)
        digits_array[i] = 0;
    blank_count = other_count = 0;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            ++digits_array[c-'0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++blank_count;
        else
            ++other_count;
    }

    for (i = 0; i < 10; ++i) {
        printf("\ndigit[%d]:",i);
        for (j = 0; j < digits_array[i]; ++j)
            printf("+");        
    }

    printf("\nblanks:\t");
    for (i = 0; i < blank_count; ++i)
        printf("+");        

    printf("\nother:\t");
    for (i = 0; i < other_count; ++i)
        printf("+");        

    printf("\n");
}
