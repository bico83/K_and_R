#include <stdio.h>

void main(void)
{
    int a, b, c;

    a = 1;
    b = 2;
    c = 3;
    
    printf("a = %d ,b = %d \n",a,b);

    if (b = a = 5 == b)
        printf("a = %d ,b = %d (if)\n",a,b);
    else
        printf("a = %d ,b = %d (else)\n",a,b);

}
