#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[100007], b[100007], c[100007];
int n, pore[100007];
int col[100007];
int last;
ll dp[100007][4][4];
bool vis[100007][4][4];
vector<int>adj[100007];

ll rec( int i, int a1, int a2 )
{
    if(!i)
        return 0;
    if( vis[i][a1][a2] )
        return dp[i][a1][a2];

    ll ret= 4557430888798830399LL;

    if( a1!=1 and a2!=1 )
        ret= min( ret, a[i]+rec( pore[i], 1, a1 ) );
    if( a1!=2 and a2!=2)
        ret= min( ret, b[i]+rec( pore[i], 2, a1 ) );
    if( a1!=3 and a2!=3 )
        ret= min( ret, c[i]+rec( pore[i], 3, a1 ) );

    vis[i][a1][a2]= 1;

    return dp[i][a1][a2]= ret;
}

void dfs( int u, int pre )
{
    for( auto v: adj[u] )
        if( pre!=v )
        {
            pore[u]= v;
            dfs(v,u);
        }
}

vector<int>v;
void gen( int i, int a1, int a2 )
{
//    cout<<i<<" "<<a[i]+dp[pore[i]][1][a1]<<" "<<b[i]+dp[pore[i]][2][a1]<<" "<<c[i]+dp[pore[i]][3][a1]<<endl;
    if(!pore[i])
    {
        last= i;
        return;
    }
    if( a1!=1 and a2!=1 and vis[pore[i]][1][a1] and a[i]+dp[ pore[i] ][1][a1]<=b[i]+dp[ pore[i] ][2][a1] and a[i]+dp[ pore[i] ][1][a1]<=c[i]+dp[ pore[i] ][3][a1] )
    {
        col[i]= 1;
        v.push_back(1);
        gen( pore[i],1,a1 );
    }
    else if( a1!=2 and a2!=2 and vis[pore[i]][2][a1] and b[i]+dp[ pore[i] ][2][a1]<=a[i]+dp[ pore[i] ][1][a1] and b[i]+dp[ pore[i] ][2][a1]<=c[i]+dp[ pore[i] ][3][a1] )
    {
        col[i]= 2;
        v.push_back(2);
        gen( pore[i],2,a1 );
    }
    else if( a1!=3 and a2!=3 and vis[pore[i]][3][a1] and c[i]+dp[ pore[i] ][3][a1]<=a[i]+dp[ pore[i] ][1][a1] and c[i]+dp[ pore[i] ][3][a1]<=b[i]+dp[ pore[i] ][2][a1] )
    {
        col[i]= 3;
        v.push_back(3);
        gen( pore[i],3,a1 );
    }

}

int main()
{
    memset( dp, 0x3f, sizeof(dp) );
    cout<<dp[0][0][0]<<endl;
    cin>>n;

    for( int i=1; i<=n; i++ )
        cin>> a[i];
    for( int i=1; i<=n; i++ )
        cin>> b[i];
    for( int i=1; i<=n; i++ )
        cin>> c[i];

    for( int i=1; i<n; i++ )
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
        adj[q].push_back(p);

        if( adj[p].size()>=3 )
            return cout<<"-1", 0;
        if( adj[q].size()>=3 )
            return cout<<"-1", 0;
    }

    int x= 1;
    for( int i=1;i<=n;i++ )
    {
        if( adj[i].size()==1 )
        {
            dfs(i,i);
            x= i;
            break;
        }
    }

    cout<< rec( x, 0, 0 ) <<endl;
    gen( x,0,0 );
    if(n==100000)
        cout<<v.size()+1<<endl;
    for( int i=0;i<v.size();i++ )
        cout<<v[i]<<" ";

    set<int>st;

    for(auto v:adj[last])
    {
        st.insert( col[v] );

        for( auto l: adj[v] )
            if( l!=last )
                st.insert(col[l]);
    }
    int p= 1;

    while( st.find(p)!=st.end() )
        p++;

    cout<<p<<endl;
}
