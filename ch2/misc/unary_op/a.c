#include <stdio.h>

void main(void)
{
    int *pint;
    int int1;

    int1 = 3;
    pint = &int1;

    printf("pint = %d\n", *pint);
    ++*pint;    /* (*pint)++; */
    printf("pint = %d\n", *pint);
    *pint++;    /* *pint; pint++; */
    printf("pint = %d\n", *pint);
    *(pint++);  /* pint++; *pint */
    printf("pint = %d\n", *pint);
    *++pint;    /* ++pint; *ping; */
    printf("pint = %d\n", *pint);

}
