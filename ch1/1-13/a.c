/* Exercise 1-13. Write a program to print a histogram of the lengths of words 
 * in its input. It is easy to draw the histogram with the bars horizontal: 
 * a vertical orientation is more challenging.
 */
#include <stdio.h>

#define IN_WORD 1
#define OUT_WORD 0

void main(void)
{
    char c;
    unsigned char state, current_word;

    state = OUT_WORD;
    current_word = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n')
            state = OUT_WORD;
        else if (state == OUT_WORD) {
            state = IN_WORD;
            printf("\n word %d:", ++current_word);
            printf("+");
        }
        else
            printf("+");
    }
}
