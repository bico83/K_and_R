#include <stdio.h>

void main(void)
{
    char char_;
    int int_;
    float float_;
    double double_;

    char *char_p;
    int *int_p;
    float *float_p;
    double *double_p;
    void *void_p;

    
    printf("sizeof(char ) = %d bytes\n",sizeof(char ));
    printf("sizeof(int ) = %d bytes\n",sizeof(int ));
    printf("sizeof(float ) = %d bytes\n",sizeof(float ));
    printf("sizeof(double ) = %d bytes\n",sizeof(double ));

    printf("sizeof(char *) = %d bytes\n",sizeof(char *));
    printf("sizeof(int *) = %d bytes\n",sizeof(int *));
    printf("sizeof(float *) = %d bytes\n",sizeof(float *));
    printf("sizeof(double *) = %d bytes\n",sizeof(double *));
    printf("sizeof(void *) = %d bytes\n",sizeof(void *));
}
