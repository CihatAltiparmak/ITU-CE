#include <stdio.h>

int main()
{
    char number[100];
    char digit;
    printf("Number: ");
    scanf("%99s", number);

    printf("Digit: ");

    scanf(" %c", &digit);

    int i = 0;
    int is_contain = 0;
    while(number[i] != '\0') {
        if(number[i] == digit) {
            is_contain = 1;
            break;
        }
        i++;
    }

    printf("%s", number);
    if (is_contain)
        printf(" contains %c.", digit);
    else
        printf(" does not contain %c.", digit);
    return 0;
} 
