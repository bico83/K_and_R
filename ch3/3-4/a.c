/*Sat Feb  4 21:32:32 CST 2017*/
/* Excersise 3.4. In a two's complement number representation, our 
 * version of itoa does not handle the largest negative number, that is 
 * the value of n equal to -(2^wordsize-1). Explain why not.
 * Modify it to print that value correctly, regardless of the machine on which 
 * it runs.
 * R: Absolute value of largest negative number is greater than 
 * 	  absolute value of largest positive number.
 * 	  e.g. For signed char:
 * 	  		CHAR_MAX = 127  (01111111b)
 * 	  	    CHAR_MIN = -128 (10000000b)
 */
#include <stdio.h>
#include <limits.h>
#include "get_str.h" 

#define MAX_LENGHT 50

void reverse(char s[]);
void _itoa1(int n, char s[]);
void _itoa2(int n, char s[]);

int main() 
{
	int input_number = INT_MIN;
	char str[MAX_LENGHT];

	/* test 1 */
	P_DEBUG("Input number = %d\n", input_number);
	P_DEBUG("Input number = 0x%X\n", input_number);

	_itoa1(input_number, str);
	P_DEBUG("Output str = %s\n", str);

	_itoa2(input_number, str);
	P_DEBUG("Output str = %s\n", str);

    return 0;
}


void _itoa2(int n, char s[])
{
	int i, sign;
	int digit;
	sign = n;

	i = 0;
	do { 
		if (n < 0) {
			digit = -(n % 10);
			n /= -10;
		}
		else {
			digit = (n % 10);
			n /= 10;
		}
		s[i++] = digit + '0';
	} while (n > 0);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void _itoa1(int n, char s[])
{
	int i, sign;
	
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do { 
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	char *end = s;
	while(*end++); /* finding EOF */
	
	end -= 2;
	while(end > s) {
		*end ^= *s; /* xor swap */
		*s ^= *end;
		*end ^= *s;

		end--, s++;
	}
}
