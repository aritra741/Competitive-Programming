#include<bits/stdc++.h>
using namespace std;

int dp[10007];

int grundy( int x )
{
    if( x==0 )
        return 0;
    if( dp[x]!=-1 )
        return dp[x];

    int mid= x/2;

    set<int>st;
    for( int i=1;i<=mid;i++ )
        st.insert( grundy(x-i) );
    int ans= 0;

    while( st.find(ans)!=st.end() )
        ans++;

    return dp[x]= ans;
}

int main()
{
    memset(dp,-1,sizeof(dp));

    for( int i=1;i<=50;i++ )
    {
        cout<<i<<" "<<grundy(i)<<endl;
    }

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

