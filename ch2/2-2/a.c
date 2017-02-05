/* Excersise 2.2. Write a loop equivalent for the for loop above without using 
 * && and ||.
 */
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int _getline(char line[], int maxline);

/* print the longest input line */
int main() 
{
    int len;            /* current line length */
    int max;            /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    int real_len;

    
    max = 0;
    while ((len = _getline(line, MAXLINE)) > 0) {
        printf("%s",line);
    }
    return 0;
}

/* getline: read a line into s, return length */
int _getline(char s[],int lim)
{
    int c, i;
    /* Original for loop
    for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
        s[i] = c;
    printf("for loop1 string: %s \n", s);
    */

    for (i=0; i < lim-1; ++i)
        if ((c=getchar()) != '\n')
            if (c != EOF)
                s[i] = c;
            else 
                break;
        else 
            break;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
        
    s[i] = '\0';
    return i;
}
