#include<bits/stdc++.h>
#define mx 100007
#define inf 1e9
using namespace std;

vector<int>adj[mx];
int nichedure[mx], uporedure[mx];
int sub_er_moddhe_mx[mx], sub_er_moddhe_2nd_mx[mx];
int par[mx];
bool mark[mx];

void dfs1( int u, int pre )
{
    nichedure[u]= -inf, uporedure[u]= -inf;
    sub_er_moddhe_mx[u]= -inf;
    sub_er_moddhe_2nd_mx[u]= -inf;

    if(mark[u] and adj[u].size()==1 )
        nichedure[u]= 0;

    for( auto v: adj[u] )
    {
        if(v==pre)
            continue;

        par[v]= u;
        dfs1( v, u );

        if( nichedure[v]>sub_er_moddhe_mx[u] )
        {
            sub_er_moddhe_2nd_mx[u]= sub_er_moddhe_mx[u];
            sub_er_moddhe_mx[u]= nichedure[v];
        }
        else if( nichedure[v]>sub_er_moddhe_2nd_mx[u] )
            sub_er_moddhe_2nd_mx[u]= nichedure[v];

        nichedure[u]= max( nichedure[v]+1, nichedure[u] );
    }
}

void dfs2( int u, int pre )
{
    if(u>1)
    {
        int x= par[u];

        if( sub_er_moddhe_mx[x]==nichedure[u] )
            uporedure[u]= max( uporedure[x]+1, sub_er_moddhe_2nd_mx[x]+2 );
        else
            uporedure[u]= max( uporedure[x]+1, sub_er_moddhe_mx[x]+2 );

//        cout<<" "<<x<<" "<<u<<" "<<sub_er_moddhe_mx[x]<<" "<<sub_er_moddhe_2nd_mx[x]<<endl;
    }

    for( auto v: adj[u] )
        if( v!=pre )
            dfs2( v, u );
}

int main()
{
    int n,m,d;
    cin>>n>>m>>d;

    for( int i=0; i<m; i++ )
    {
        int x;
        cin>>x;

        mark[x]= 1;
    }

    for( int i=1; i<n; i++ )
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1( 1,1 );
    uporedure[1]= 0;
    dfs2( 1,1 );

    int ans= 0;

    for( int i=1; i<=n; i++ )
    {
        if( max( nichedure[i], uporedure[i] )<=d and max( nichedure[i], uporedure[i] )>=0 )
            ans++;
    }

    cout<< ans <<endl;
}
