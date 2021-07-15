#include <stdio.h>

int main()
{
    double fah = 0.0;
    printf("Write tempeature (Fahrenheight): ");
    scanf("%lf", &fah);
    
    double cel = 5 * (fah - 32) / 9.0;
    printf("\n%lf\n", cel);
}
