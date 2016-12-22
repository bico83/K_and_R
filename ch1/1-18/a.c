/* Wed Nov 16 21:26:28 CST 2016
 * Excersise 1.18. Write a program to remove trailing blanks and tabs from each 
 * line of input, and to delete entirely blank lines.
 */
#include <stdio.h>
#define MAXLINE 100 /* maximum input line length */

int _getline(char line[], int maxline);
void copy(char to[], char from[]);
void rm_trailing_blanks(char to[], char from[], int size);

/* print the longest input line */
int main() 
{
    int len;            /* current line length */
    char line[MAXLINE]; /* current input line */
    char clean_line[MAXLINE]; /* line with no trailin blank */
    int real_len;
    
    while ((len = _getline(line, MAXLINE)) > 0) {
        rm_trailing_blanks(clean_line, line, len);/* remove trailing blanks */
        printf("%s",clean_line);
    }
    return 0;
}

/* getline: read a line into s, return length */
int _getline(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
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

/* rm_trailing_blanks: remove any trailing blanks or tabs inside 'from' and 
 * store result in 'to'*/ 
void rm_trailing_blanks(char to[], char from[], int size) 
{
    copy(to, from);
    while (to[--size] == ' ' || to[size] == '\t' || to[size] == '\n')
        ;
    to[++size] = '\n';
    to[++size] = '\0';
}
