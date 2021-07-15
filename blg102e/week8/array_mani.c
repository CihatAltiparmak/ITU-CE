#include <stdio.h>
#include <stdio.h>

int n, m;
int dp[100000];
int ans = 0;

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int l, r, v;
        scanf("%d %d %d", &l, &r, &v);
        
        for(int j = l; j <= r; j++)
        {
            dp[j] += v;
            if(dp[i] > ans)
                ans = dp[j];
        }
    }

    printf("%d", ans);
}
