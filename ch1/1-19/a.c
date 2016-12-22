/* Wed Nov 16 22:20:58 CST 2016
 * Excersise 1.19. Write a function reverse(s) that reverses the character 
 * string s. Use it to write a program that reverses its input a line at a time.
 */
#include <stdio.h>
#define MAXLINE 100 /* maximum input line length */

int _getline(char line[], int maxline, int *real_len);
void copy(char to[], char from[]);
void reverse(char s[]);

/* print the longest input line */
int main() 
{
    int len;            /* current line length */
    char line[MAXLINE]; /* current input line */
    int real_len;
    
    while ((len = _getline(line, MAXLINE, &real_len)) > 0) {
        printf("original:%s", line);
        reverse(line);
        printf("reverse:%s", line);
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

/* reverse: reverse the contents of s */
void reverse(char s[])
{
    int i = 0;
    int low, up;
    char tmp;

    while (s[i] != '\0')
        ++i;

    i = (s[i-1] == '\n') ? i-2 : i-1;

    low = 0;
    up = i;

    while (low < up) {
        tmp = s[up];
        s[up] = s[low];
        s[low] = tmp;
        ++low; 
        --up;
    }
}
