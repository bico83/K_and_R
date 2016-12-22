/* Excersise 1.17. Write a program to print all input lines that are longer 
 * than 80 characters.
 */
#include <stdio.h>
#define MAXLINE 10 /* maximum input line length */
#define LONG_LINE 80 /* lines longer than this will be printed */

int _getline(char line[], int maxline, int *real_len);

/* print only long input lines */
int main() 
{
    int max;            /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char long_line[MAXLINE]; /* long line saved here */
    int real_len;
    
    max = 0;
    while ((_getline(line, MAXLINE, &real_len)) > 0) {
        if (real_len > LONG_LINE) {
            printf("long line; lenght %d, %s\n", real_len, line);
        }
    }
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
        do {
            (*real_len)++;
        } while (getchar() != '\n');
    }
        
    s[i] = '\0';
    return i;
}
