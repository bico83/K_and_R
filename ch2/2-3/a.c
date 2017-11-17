/* Sun Nov 27 21:33:46 CST 2016
 * Excersise 2.3. Write a function htoi(s), which converts a string of 
 * hexadecimal digits (including an optional 0x or 0X) into its equivalent 
 * integer value. The allowable digitas are 0 through 9, a through f, and 
 * A through F.
 *
 * Notes: 
 *      i was never incremented in htoi().
 *      There was no return value in htoi().
 */
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

#define ishex(c) ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
#define isdigit(c) (c >= '0' && c <= '9')
                        

int _getline(char s[],int lim);
int htoi(char *line);
char tolower_(char c);


/* print the longest input line */
int main() 
{
    int len;            /* current line length */
    char line[MAXLINE]; /* current input line */
    int result;
    
    while ((len = _getline(line, MAXLINE)) > 0) {
        result = htoi(line);
        printf("result = 0x%X (%d)\n",result,result);
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


int htoi(char *line)
{
    int i;
    unsigned int result;
    unsigned char nibble;
    i = 0;
    if (line[i] == '0' && (line[i+1] == 'x' || line[i+1] == 'X'))
        i = i+2;

    result = 0;
    while (line[i] != '\0' && line[i] != '\n' && (ishex(line[i]) || isdigit(line[i])) ) {
        if (isdigit(line[i]))
            nibble = line[i] - '0';
        else {
            line[i] = tolower_(line[i]);
            nibble = line[i] - 'a' + 0xAU;
        }
        result = (result << 4) | nibble;
        ++i;
    }
    return result;
}

char tolower_(char c)
{
    if (c >= 'a' && c <= 'z')
        return c;               /* already a lower-case letter */
    else if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';   /* convert to lower-case */
    else
        return c;               /* not even a letter D: */
}
