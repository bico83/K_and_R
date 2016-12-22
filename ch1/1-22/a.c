/* Sun Nov 20 13:38:16 CST 2016
 * Excersise 1.22. Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blanks character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before the specified column.
 */
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define TAB_STOP 8 /* keep the tabstop just like the kernel does */
#define COL_LIMIT 80 /* fold each line if is greater than this */

int _getline(char line[], int maxline);
void fold(char folded_line[], char line[]);

/* print the longest input line */
int main() 
{
    int len;            /* current line length */
    int max;            /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char folded_line[MAXLINE]; /* input line with no tabs */
    int real_len;
    
    max = 0;
    while ((len = _getline(line, MAXLINE)) > 0) {
        fold(folded_line, line);
        printf("%s",folded_line);
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


/* fold:  */
void fold(char folded_line[], char line[])
{
    int i, j, k;
    int sob, sow, eow; /* start of blank, start of word, end of word */
    int f_offset;
    
    i = j = k =  0;
    f_offset = 0;
    while ((folded_line[j] = line[i]) != '\0') {
        if (line[i] == ' ') {
            sob = eow = sow = i;
            /* find START_OF_WORD */
            ++f_offset;
            while (line[++sow] == ' ')
                ++f_offset;
            eow = sow;
            /* find END_OF_WORD */
            while (line[eow] != ' ' && line[eow] != '\n') {
                ++eow;
                ++f_offset;
            }
            /* fold the line */ 
            if (f_offset > COL_LIMIT) {
                folded_line[j] = '\n';
                ++j;
                f_offset = 0;

                k = sow;
            }
            else 
                k = sob;

            /* copy verbatim word */
            while (k < eow)
                folded_line[j++] = line[k++];
            i = eow;
        }
        else {
            ++i;
            ++j;
            ++f_offset;
        }
    }
}
