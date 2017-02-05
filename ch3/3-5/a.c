/* Excersise 3.5. 
 * Write athe function itob/n,s,b) that converts the integer n into a base n
 * character representation in the string s.
 * In particular, itob(n,s,16 formats s as a hexadecimal integer in s.
 */
#include <stdio.h>
#include "get_str.h"

#define AR_SIZE 50

int itob(int n, char *s, int b);
int reverse (char *s);

int main() 
{
	char str[AR_SIZE];
	int base = 2;
	int number = 0x22;

	/* test 1 */
	P_DEBUG("\nInput number: 0x%X\n", number);
	P_DEBUG("Base to convert: %d\n", base);

	itob(number, str, base);

	P_DEBUG("Out string: %s\n", str);

	/* test 2 */
	base = 6;
	P_DEBUG("\nInput number: 0x%X\n", number);
	P_DEBUG("Base to convert: %d\n", base);

	itob(number, str, base);

	P_DEBUG("Out string: %s\n", str);

	/* test 3 */
	base = 10;
	P_DEBUG("\nInput number: 0x%X\n", number);
	P_DEBUG("Base to convert: %d\n", base);

	itob(number, str, base);

	P_DEBUG("Out string: %s\n", str);
	
	
    return 0;
}


int itob(int n, char *s, int b)
{
	int i, digit;

	if ( b < 2 || !s)
		return -1;

	i = 0;
	while (n) {
		digit = n % b;
		n /= b;

		if (digit < 0) {
			digit = -digit;
			n = -n;
		}
		
		s[i++] = digit + '0';
	}

	s[i] = '\0';

	reverse(s);

	return 0;
}

int reverse (char *s)
{
	char *end = s;
	
	if (!s)
		return -1;

	while (*end++) ;
	end -= 2;

	while (s < end) {
		*s ^= *end;
		*end ^= *s;
		*s ^= *end;
		
		s++;
		end--;
	}
	return 0;
}
