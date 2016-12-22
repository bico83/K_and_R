/* Excersise 1.20. Write a program detab that replaces tabs in the input with
 * the proper number of blanks to space to the next tab stop. Assume a fixed set
 * of tab stops, say every n columns. 
 * Should n be a variable or a symbolic parameter?
 */
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define TAB_STOP 8 /* keep the tabstop just like the kernel does */

int _getline(char line[], int maxline);
void copy(char to[], char from[]);
void detab(char detab_line[], char line[]);

/* print the longest input line */
int main() 
{
    int len;            /* current line length */
    int max;            /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char detab_line[MAXLINE]; /* input line with no tabs */
    int real_len;
    
    max = 0;
    while ((len = _getline(line, MAXLINE)) > 0) {
        detab(detab_line, line);
        printf("%s",detab_line);
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

/* detab: remove tabs from line; replace by TAB_STOP spaces */
void detab(char detab_line[], char line[])
{
    int i, j, k;
    
    i = j =  k = 0;
    while ((detab_line[j] = line[i]) != '\0') {
        if (line[i] == '\t') {
            while (k++ < TAB_STOP && j < MAXLINE) {
                detab_line[j++] = ' ';
            }
            k = 0;
        }
        else 
            ++j;

        ++i;
    }
}
