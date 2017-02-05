#ifndef GET_STR_H
#define GET_STR_H

#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */
#define TAB_STOP 8 /* keep the tabstop just like the kernel does */

#ifdef DEBUG
#define P_DEBUG(frmt, ...) printf(frmt, ##__VA_ARGS__)
#else
#define P_DEBUG(frmt, ...) 
#endif

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

#endif
