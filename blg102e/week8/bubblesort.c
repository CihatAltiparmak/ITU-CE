#include <stdio.h>
#include <stdlib.h>

int dp[100000];
int n;

int main()
{
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
        scanf("%d", &dp[i]);

    int limit = n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < limit - 1; j++)
        {
            if(dp[j] >  dp[j + 1])
            {
                int tmp = dp[j];
                dp[j] = dp[j + 1];
                dp[j + 1] = tmp;
            }
        }
        limit--;
    }
    
    for(int i = 0; i < n; i++)
        printf("%d ", dp[i]);  

    printf("\n");     

}
