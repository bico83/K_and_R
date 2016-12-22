#include <stdio.h>

void main(void)
{
/* The following example tries to demonstrate the conversion of types
 * when using mixed float and int types.
 *
 *  Integer operands                    -> integer operation
 *  At least one Floating point operand -> float operation
 */

    int int_a;
    float float_a;

    int_a = 3.0/2.0;
    float_a = 3.0/2.0;
    printf("3.0/2.0 = %ff\n", float_a);
    printf("3.0/2.0 = %dd\n\n", int_a);

    int_a = 3/2.0;
    float_a = 3/2.0;
    printf("3/2.0 = %ff\n", float_a);
    printf("3/2.0 = %dd\n\n", int_a);

    int_a = 3.0/2;
    float_a = 3.0/2;
    printf("3.0/2 = %ff\n", float_a);
    printf("3.0/2 = %dd\n\n", int_a);

    int_a = 3/2;
    float_a = 3/2;
    printf("3/2 = %ff\n", float_a);
    printf("3/2 = %dd\n\n", int_a);
    
}
