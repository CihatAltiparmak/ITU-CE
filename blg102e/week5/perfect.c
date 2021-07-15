#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int x = 0;

    for(int i = 1; i < n; i++)
    {
        if(n % i == 0)
            x += i;
    }

    if(x == n)
        printf("The number is perfect number\n");
    else
        printf("The number is not perfect number\n");
}
