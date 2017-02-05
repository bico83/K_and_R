/* Excersise 3.3. Write a function expand(s1,s2) that expands shorthand
 * notations like a-z in the string s1 into the equivalent complete list
 * abc...xyz in s2. 
 * Allow for letters of either case and digits, and be prepared to handle 
 * cases like a-b-c and a-z0-9 and -a-z.
 * Arrange that a leading or trailing - is taken literally.
 */
#include <stdio.h>
#include "get_str.h" 

#define MAX_LENGHT 50

#define IS_DASH(c) (c=='-')
#define IS_CHAR(c) (c>0x00 && c<=0x7F)

int expand(char *s1, char *s2);

int main() 
{
	char user_str[MAX_LENGHT];
	char expanded_str[MAX_LENGHT];

	while(_getline(user_str,MAX_LENGHT) != EOF) {
		expand(user_str, expanded_str);
		P_DEBUG("Input: %s", user_str);
		P_DEBUG("Output: %s\n", expanded_str);
	}
    return 0;
}

/* expand s1 into s2 */
/* TODO: Warning, this function does not check ptr boundaries */
int expand(char *s1, char *s2)
{
	char exp_char;
	while(*s2++ = *s1++) {
		if (!*s1) /* next char is EOF */
			continue;
		if (IS_DASH(*(s1-1)) || !IS_DASH(*s1) || IS_DASH(*(s1+1)))
			continue;
		if (*(s1-1) < *(s1+1)) { /* lets see if we have CHAR1-CHAR2 */
			exp_char = *(s1-1) + 1;
			for (; *(s2-1) < *(s1+1) ; exp_char++, s2++) 
				*s2 = exp_char;
			s1 += 2;
		}
	}
	return 0;
}
