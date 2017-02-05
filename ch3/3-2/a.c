/* Excersise 3.2. Write a function escape(s,t)
 * that converts characters like newline and tab into visible escape sequences
 * like \n and \t as it copies the string t to s.
 * Use switch. Write a function for the other direction as well, converting 
 * escape sequences int the real characters.
 */
#include <stdio.h>
#define MAX_LENGTH 50

#ifdef DEBUG
#define P_DEBUG(fmt,...) printf(fmt, ##__VA_ARGS__)
#else
#define P_DEBUG(fmt,...)
#endif

void escape(char *s, char *t);
int _getline(char line[], int maxline);


int main() 
{
	char user_str[MAX_LENGTH];
	char out_str[MAX_LENGTH];

	_getline(user_str,MAX_LENGTH);

	escape(out_str,user_str);
	P_DEBUG("Input: %s",user_str);
	P_DEBUG("Output: %s\n",out_str);

    return 0;
}


void escape(char *s, char *t)
{
	/*copies string "t" to "s"*/
	while((*s++ = *t++) != '\0') {
		switch (*(s-1)) {
			case '\t': 
				*(s-1) = '\\';
				*s++ = 't';
			break;

			case '\n':
				*(s-1) = '\\';
				*s++ = 'n';
			break;

			default:
			break;
		}
	}
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
