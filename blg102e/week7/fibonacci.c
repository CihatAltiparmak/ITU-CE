#include <stdio.h>

int main()
{
    int index;
    printf("Enter the index of the Fibonacci series\n");
    scanf("%d", &index);
    
    int i = 0;
    int f1 = 0, f2 = 1;
    while(i < index - 1)
    {
        int tmp = f2;
        f2 += f1;
        f1 = tmp;
        i++;
    }

    printf("%d\n", f1);

    return 0;
}
