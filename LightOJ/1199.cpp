#include<bits/stdc++.h>
using namespace std;

int dp[10007];

int grundy( int x )
{
    if( x<3 )
        return 0;
    if( dp[x]!=-1 )
        return dp[x];

    int mid= (x&1)?x/2:(x-1)/2;

    bitset<16400>st;
    st.set();

    for( int i=1;i<=mid;i++ )
        st[grundy(i)^grundy(x-i)]= 0;

    int ans= st._Find_first();
    return dp[x]= ans;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        int n;
        scanf("%d", &n);

        int ans= 0;

        for( int i=0;i<n;i++ )
        {
            int p;
            scanf("%d", &p);

            ans^= grundy(p);
        }

        printf("Case %d: ", t);

        if(!ans)
            printf("Bob\n");
        else
            printf("Alice\n");
    }
}
