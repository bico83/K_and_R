#include <stdio.h>
/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300; floating-point version */
main()
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
        fahr = (9.0/5.0) * (celsius) + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
