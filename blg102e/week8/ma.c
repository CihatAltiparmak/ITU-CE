#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n];
    double cum[n];
    double sim[n];
    int sum[n];
    
    scanf("%d", &a[0]);
    sum[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum[i] = a[i] + sum[i - 1];
    }

    for(int i = 0; i < n; i++)
        cum[i] = (double)sum[i] / (i + 1);  

    for(int i = m - 1; i < n; i++)
    {
        sim[i] = (double)(sum[i] - sum[i - m]) / m;
    }

    for(int i = 0; i < n; i++)
       printf("%.3lf ", cum[i]);

    printf("\n");
    for(int i = 0; i < n; i++)
        printf("%.3lf ", sim[i]);

    printf("\n");

}
