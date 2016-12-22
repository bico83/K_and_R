#include <stdio.h>
/* Exercise 1-8. Write a program to count blanks, tabs and newlines.*/
void main(void)
{
    int c;
    int blanks_c, tabs_c, nl_c;

    blanks_c = tabs_c = nl_c = 0;

    while ((c = getchar()) != EOF){
        if (c == ' ')
            ++blanks_c;
        else if (c == '\t')
            ++tabs_c;
        else if (c == '\n')
            ++nl_c;
    }
    printf("blanks = %d\n", blanks_c);
    printf("tabs = %d\n", tabs_c);
    printf("new lines = %d\n", nl_c);
}
