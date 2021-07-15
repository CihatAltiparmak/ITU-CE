#include <stdio.h>

int main()
{
    char choice = ' ';

    double state = 0;

    scanf("%lf %c", &state, &choice);

    if (choice == 'F') {
        if (state >= 212) {
            printf("It's gas.\n");
        } else if (state > 32) {
            printf("It's liquid\n");
        } else {
            printf("It's solid.\n");
        }
    } else if (choice == 'C') {
        if (state >= 100) {
            printf("It's gas.\n");
        } else if (state > 0) {
            printf("It's liquid\n");
        } else {
            printf("It's solid.\n");
        }
    }

    return 0;
}
