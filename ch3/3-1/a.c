/* Excersise 3.1. Our binary search makes two tests inside the loop, when one
 * would suffice (at the price of more tests outside.) 
 * Write a version with only one test inside the loop and measure the 
 * difference in run-time.
 */
#include <stdio.h>
#define AR_SIZE 6

#ifdef DEBUG
#define P_DEBUG(fmt,...) printf(fmt, ##__VA_ARGS__)
#else
#define P_DEBUG(fmt,...)
#endif

#define XQUOTE(s) QUOTE(s) 
#define QUOTE(s) #s
#define ARRAY {1,2,3,4,5,6}

int binsearch1(int x, int v[], int n);
int binsearch2(int x, int v[], int n);
int binsearch3(int x, int v[], int n);


int main() 
{
	int ordered_array[AR_SIZE] = ARRAY;
	int to_search = 0;
	
	P_DEBUG("Array = %s\n",XQUOTE(ARRAY));

	printf("%d found at: %d\n",to_search,binsearch2(to_search,ordered_array,AR_SIZE));
	printf("%d found at: %d\n",to_search,binsearch3(to_search,ordered_array,AR_SIZE));
    return 0;
}


int binsearch1(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid + 1;
		else if (x > v[mid])
			low = mid + 1;
		else /* found match */
			return mid;
	}
	return -1; /* no match */
}

int binsearch2(int x, int v[], int n)
{
	int low, high, mid;

	low = 0; 
	high = n;

	while (low < high) {
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid;
		else if (x > v[mid])
			low = mid;
		else
			return mid; 
	}
	return -1;
}

int binsearch3(int x, int v[], int n)
{
	int low, high, mid;

	low = 0; 
	high = n;

	while (low < high) {
		mid = (low+high)/2;
		if (x < v[mid])
			high = mid;
		else
			low = mid+1;
	}
	if (x == v[mid])
		return mid;
	else 
		return -1;
}
