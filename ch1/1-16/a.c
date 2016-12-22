/* Excersise 1.16. Revise the main routine of the longest-line program so it
 * will correctly print the lenght of arbitrary long input lines, and as much as
 * possible of the text.
 */
#include <stdio.h>
#define MAXLINE 10 /* maximum input line length */

int _getline(char line[], int maxline, int *real_len);
void copy(char to[], char from[]);

/* print the longest input line */
int main() 
{
    int len;            /* current line length */
    int max;            /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    int real_len;
    
    max = 0;
    while ((len = _getline(line, MAXLINE, &real_len)) > 0)
        if (real_len > max) {
            max = real_len;
            copy(longest, line);
        }
    if (max > 0) /* there was a line */
        printf("longest; lenght %d, %s", max, longest);
    return 0;
}

/* getline: read a line into s, return length */
int _getline(char s[],int lim,int *real_len)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    *real_len = i;
    if (c == '\n') {
        s[i] = c;
        ++i;
        (*real_len)++;
    }
    else if (i == lim-1) {
        while (getchar() != '\n')
            (*real_len)++;
    }
        
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
