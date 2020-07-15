#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll lcm( ll x, ll y )
{
    return (x*y)/__gcd(x,y);
}

struct edge
{
    int v,g,l;

    edge( int V, int G, int L )
    {
        v= V,
        g= G,
        l= L;
    }
};

vector<edge> E[110];
int ans[110];

void clean( int n )
{
    for(int i=1;i<=n;i++)
        ans[i]= 0;
}

bool dfs( int u )
{
    for(int i=0;i<E[u].size();i++)
    {
        int v= E[u][i].v;
        int g= E[u][i].g;
        int l= E[u][i].l;

        if( ans[v] )
        {
            if( __gcd( ans[u],ans[v] )!= g )
                return 0;
            if( lcm( ans[u],ans[v] )!= l )
                return 0;
            continue;
        }

        int tmp= (l/ans[u])*g;

        if( tmp<=0 or tmp>1e6 )
            return 0;
        ans[v]= tmp;

        if( !dfs(v) )
            return 0;
    }

    return 1;
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int p,q,g,l;
        cin>>p>>q>>g>>l;

        E[p].push_back( edge( q,g,l ) );
        E[q].push_back( edge( p,g,l ) );
    }

    for( int i=1;i<=n;i++ )
    {
        if( ans[i] or !E[i].size() )
            continue;

        edge temp= E[i][0];

        for(int j=temp.g;j<=temp.l;j+=temp.g)
        {
            ans[i]= j;
            if( !dfs( i ) )
                clean( n );
            else
                break;
        }

        if( !ans[i] )
            return cout<<"NO\n", 0;
    }

    cout<<"YES\n";
    for(int i=1;i<=n;i++)
        cout<< (ans[i]?ans[i]:1) <<" ";
}
