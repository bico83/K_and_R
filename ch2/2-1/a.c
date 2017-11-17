/* Sun Nov 20 23:03:44 CST 2016
 * Excersise 2.1. Write a program to determine the ranges of char, short, int
 * and long variables, both signed and unsigned, by printing appropriate values
 * from standard headers and by direct computation.
 * Harder if you comput them: determine the ranges of the various floating-point
 * types
 */
#include <stdio.h>
#include <limits.h>
#include <float.h>

/* Ranges of char, short, int and long */
int main() 
{
    char char_;                 /* WARNING: char's signess is unespecified */
    signed char_s;
    unsigned char_u;

    short short_s;              /* by default, short is "signed short int" */
    unsigned short short_u;

    int int_s;                  /* by default, int is "signed int" */
    unsigned int_u;

    long long_s;                /* by default, long is "signed long int" */
    unsigned long_u;

    float float_;
    double double_;

    
    printf("******************************   CHAR    *************************"
           "*************\n");
    printf("char              %15d to %15d\n", CHAR_MIN, CHAR_MAX);
    printf("signed char       %15d to %15d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char     %15d to %15d\n", 0, UCHAR_MAX);
    printf("******************************   SHORT   *************************"
           "*************\n");
    printf("(signed) short    %15d to %15d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short    %15u to %15u\n", 0, USHRT_MAX);
    printf("******************************   INT     *************************"
           "*************\n");
    printf("(signed) int      %15d to %15d\n", INT_MIN, INT_MAX);
    printf("unsigned int      %15u to %15u\n", 0U, UINT_MAX);
    printf("******************************  LONG     *************************"
           "*************\n");
    printf("(signed) long     %15li to %15li\n", LONG_MIN, LONG_MAX);
    printf("unsigned long     %15li to %15lu\n", 0UL, ULONG_MAX);
    printf("******************************  FLOAT    *************************"
           "*************\n");
    printf("(signed) float    %15e to %15e\n", FLT_MIN, FLT_MAX);
    printf("(signed) double   %15e to %15e\n", DBL_MIN, DBL_MAX);
    
    
    
    return 0;
}

