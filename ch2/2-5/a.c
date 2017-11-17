/* Excersise 2-5
 * Write a function any(s1,s2), which returns the first location in a string s1
 * where any character from the string s2 occurs, or -1 if s1 contains no 
 * characters from s2. (The standard library function strpbrk does the same job
 * but returns a pointer to the location.)
 */
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define TAB_STOP 8 /* keep the tabstop just like the kernel does */


#ifdef DEBUG
#define P_DEBUG(frmt, ...) printf(frmt, ##__VA_ARGS__)
#else
#define P_DEBUG(frmt, ...)
#endif

int _getline(char line[], int maxline);
int any(char s1[], char s2[]);

/* print first occurrance of [aeiou] in line[] */
int main() 
{
    int len;            /* current line length */
    char line[MAXLINE]; /* current input line */
	int occurrance;
    
    while ((len = _getline(line, MAXLINE)) > 0) {
        occurrance = any(line, "aeiou");
        printf("\noccurrance:%i",occurrance);
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

/* Return the first location in s1 where any character from s2 occurs, -1 if 
 * s1 contains no characters from s2 */
int any(char s1[], char s2[])
{
	int i, j;
	P_DEBUG("s1 = %s",s1);
	P_DEBUG("s2 = %s",s2);

	j = 0;
	for (i = 0; s1[i] != '\0' && j != -1; ++i) {
		while (s1[i] != s2[j] && s2[j] != '\0')
			++j;	
		if (s1[i] == s2[j])
			j = -1;
		else 
			j = 0;
	}

	return s1[i] == '\0'? -1 : i-1;
}
