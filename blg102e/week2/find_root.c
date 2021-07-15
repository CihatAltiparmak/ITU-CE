#include <stdio.h>
#include <math.h>

int main()
{
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    printf("Values for polinom (ex: 3 2 1 ): \n");
    scanf("%lf %lf %lf", &a, &b, &c);

    double delta = sqrt(b*b - 4 * a * c);


    double x1 = (-b + delta) / (2 * a);
    double x2 = (-b - delta) / (2 * a);

    printf("x1: %lf x2: %lf\n", x1, x2);
}
