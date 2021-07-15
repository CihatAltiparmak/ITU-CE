#include <stdio.h>


int main()
{
    printf("Enter the numbers\n");
    int p[4];
    scanf("%d %d %d %d", p, p+1, p+2, p+3);

    int i = 0;
    while(i < 3)
    {
        if(p[i] < p[i + 1])
        {
            int tmp = p[i];
            p[i] = p[i + 1];
            p[i + 1] = tmp;
        }
        i++;
    }

    printf("%d\n", p[3]);
    return 0;
}  
