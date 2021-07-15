#include <stdio.h>
#include <math.h>

int main()
{
    double height = 0.0;
    double weight = 0.0;
    double bsa = 0.0;

    printf("height (cm): ");
    scanf("%lf", &height);

    printf("weight (gr): ");
    scanf("%lf", &weight);

    bsa = 0.0003207 *  pow(height, 0.3) * pow(weight , 0.7285 - 0.0188 * log10(weight));

    printf("bsa: %lf\n", bsa);

    return 0;
}
