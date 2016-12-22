#include <stdio.h>
/* Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1 */
void main(void)
{
    int c, res;

    c = getchar();
    while (1) {
        /* Print result of getchar() != EOF */
        printf("%d\n", c != EOF);
        c = getchar();
    }
    /* Never reached */
}
