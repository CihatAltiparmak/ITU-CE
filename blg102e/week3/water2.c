#include <stdio.h>

int main()
{
    char choice = ' ';

    double state = 0;
    double meter = 0;
    scanf("%lf %c", &state, &choice);
    scanf("%lf", &meter);

    if (choice == 'F') {
        state = (state - 32) * 5 / 9.0;
    }
    else if(choice != 'C')
    {
        printf("Error\n");
        return 0;
    }

    double dec = meter / 300.0;
    if (state >= 100 - dec) {
        printf("It's gas.\n");
    } else if (state > 0 - dec) {
        printf("It's liquid\n");
    } else {
        printf("It's solid.\n");
    }

    return 0;
}
