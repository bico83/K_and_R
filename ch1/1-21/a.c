/* Excersise 1.21. Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the same
 * tab stops as for detab.
 * When either a tab or a signle blank would suffice to reach a tab stop, which
 * should be given preference?
 */
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define TAB_STOP 8 /* keep the tabstop just like the kernel does */

int _getline(char line[], int maxline);
void copy(char to[], char from[]);
void detab(char detab_line[], char line[]);
void entab(char entab_line[], char line[]);

/* print the longest input line */
int main() 
{
    int len;            /* current line length */
    int max;            /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char entab_line[MAXLINE]; /* input line with no tabs */
    int real_len;
    
    max = 0;
    while ((len = _getline(line, MAXLINE)) > 0) {
        entab(entab_line, line);
        printf("%s",entab_line);
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

/* entab: remove blanks from line; replace by TABS, according to TAB_STOP*/
void entab(char entab_line[], char line[])
{
    int i, j, k;
    int blank_count;
    
    i = j =  k = 0;
    while ((entab_line[j] = line[i]) != '\0') {
        blank_count = 0;
        /* blank detection */
        if (line[i] == ' ') {
            do {
                if (!((i+1) % TAB_STOP)) { /* bug: !(i+1 % TAB_STOP) */
                    entab_line[j++] = '\t';
                    blank_count = 0;
                }
                else {
                    ++blank_count;
                }
            } while (line[++i] == ' ');

            /* discharge blanks */
            while (blank_count) {
                entab_line[j++] = ' ';
                --blank_count;
            }
        }
        else {
            ++i;
            ++j;
        }
    }
}
