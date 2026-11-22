#include<stdio.h>

long long dp[100005][2];
long long a[100005];

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }

    dp[1][0]=a[1];
    dp[1][1]=0;

    for(int i=2;i<=n;i++)
    {
        if(dp[i-1][0]>dp[i-1][1])
            dp[i][0]=dp[i-1][0]+a[i];
        else
            dp[i][0]=dp[i-1][1]+a[i];

        dp[i][1]=dp[i-1][0];
    }

    if(dp[n][0]>dp[n][1])
        printf("%lld\n",dp[n][0]);
    else
        printf("%lld\n",dp[n][1]);

    return 0;
}
