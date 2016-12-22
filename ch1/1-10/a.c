/* Exercise X-Y. Write a program to copy its input to its output, replacing 
 * each tab by \t, each backpace by \b, and each backslash by \\. 
 * This makes tabs and backspaces visible in an unambiguous way.
 */
#include <stdio.h>

void main(void)
{
    char c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') 
            printf("%s","\\t");
        else if (c == '\b') 
            printf("%s","\\b");
        else if (c == '\\') 
            printf("%s","\\\\");
        else 
            printf("%c",c);
    }
}
