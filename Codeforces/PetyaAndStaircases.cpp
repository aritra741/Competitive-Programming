#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector <ll> dirty;
vector <ll> ::iterator it;
ll n,m;

bool dp[3007][4];
bool vis[3007][4];
int mx= -1;

bool rec( int i, int cant )
{
    if( i==m )
    {
        if(mx>=2)
            return 0;
        return 1;
    }

    if(vis[i][cant])
        return dp[i][cant];

    bool ans=0;

    if(dirty[i+1]-dirty[i]==1 )
        cant++;
    else
        cant=0;

    mx= max( mx, cant );

    ans= rec( i+1, cant );

    return dp[i][cant]= ans;
}

int main()
{
    cin>>n>>m;

    for(ll i=0;i<m;i++)
    {
        ll p;
        scanf("%lld", &p);
        dirty.push_back(p);

        if(p==1 or p==n)
        {
            printf("NO\n");
            return 0;
        }
    }

    sort( dirty.begin(), dirty.end() );

    if( rec(0, 0) )
        printf("YES\n");
    else
        printf("NO\n");
}
