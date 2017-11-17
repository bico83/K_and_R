/* Excersise 2-4. Write an alternative version of squeeze(s1,s2) that deletes
 * each character in s1 that matches any character in the string s2.
 */
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define TAB_STOP 8 /* keep the tabstop just like the kernel does */

#define DEBUG

#ifdef DEBUG
#define P_DEBUG(frmt, ...) printf(frmt, ##__VA_ARGS__)
#else
#define P_DEBUG(frmt, ...) 
#endif

void squeeze(char [], char []);
int _getline(char line[], int maxline);

/* print the longest input line */
int main() 
{
    int len;            /* current line length */
    char line[MAXLINE]; /* current input line */
    
    while ((len = _getline(line, MAXLINE)) > 0) {
        squeeze(line, "aeiou\n");
        printf("Out:%s\n",line);
    }
    return 0;
}

/* squeeze: delete all characters of s2 from s1 */
void squeeze(char s1[], char s2[])
{
    int i, j, k;

    P_DEBUG("s1=%s",s1);
    P_DEBUG("s2=%s",s2);
    
    for (i = j = 0; s1[i] != '\0'; i++) {
        for (k = 0; s2[k] != '\0' ; k++) {
            if (s1[i] == s2[k])
                break;
        }
        if (s2[k] == '\0')
            s1[j++] = s1[i];
    }

    s1[j] = '\0';
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
