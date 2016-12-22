/* Excersise 1.15. Rewrite the temperature conversion program (1-4) to use a 
 * function for conversion.
 */
#include <stdio.h>
/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300; floating-point version */

float cel_to_fahr(float celsius);

void main()
{
    float fahr, celsius;
    float lower, upper, step;
    lower = -17;
    upper = 150;
    step = 10;
    /* lower limit of temperatuire scale */
    /* upper limit */
    /* step size */
    printf("Celcius Fahr\n");
    celsius = lower;
    while (celsius <= upper) {
        fahr = cel_to_fahr(celsius);
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}

float cel_to_fahr(float celsius)
{
    return 9.0 / 5.0 * celsius + 32.0;
}
