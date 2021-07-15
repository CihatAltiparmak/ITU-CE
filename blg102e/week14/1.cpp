#include <stdio.h>

void swap (int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void swapr(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

int main()
{
    int x = 10;
    int y = 45;
    swap(&x, &y);
    printf("x = %d \n", x);
    printf("y = %d \n", y);
    swapr(x, y);
    printf("x = %d \n", x);
    printf("y = %d \n", y);
    return 0;
}
