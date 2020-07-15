#include<bits/stdc++.h>
using namespace std;

bool dp[1048580];
int vis[1048580];
int pre[1048580];
int arr[25], side;
int n,p;

bool rec( int len, int mask )
{
    if( len>side )
        return 0;
    if( len==side and __builtin_popcount(mask)==n )
        return 1;
    if( len==side )
        len= 0;
    if( vis[mask]==p )
        return dp[mask];

    int sum= pre[mask];

    bool ret= 0;
    for( int j=0; j<n; j++ )
    {
        if( mask&(1<<j) )
            continue;

        ret|= rec( len+arr[j], mask|(1<<j) );

        if(ret)
            break;
    }

    vis[mask]= p;
    return dp[mask]= ret;
}


int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        memset( pre, -1, sizeof(pre) );

        scanf("%d", &n);
        int sum= 0;
        pre[0]= 0;
        for( int i=0; i<n; i++ )
            scanf("%d",&arr[i]), sum+= arr[i], pre[1<<i]= arr[i];

        for(int b=0, sz=(1<<n); b<sz; ++b)
        {
            if(pre[b] != -1)
                continue;
            int msb = b & (-b);
            pre[b] = pre[msb] + pre[b ^ msb];
        }
        if( sum%4 )
        {
            printf("no\n");
            continue;
        }

        side= sum/4;
        p++;

        bool ok= rec( 0, 0 );
//        cout<<ok<<endl;
        if(ok)
            printf("yes\n");
        else
            printf("no\n");
    }
}
