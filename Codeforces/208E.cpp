#include<bits/stdc++.h>
#define mx 100007
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

string val[mx];
unordered_map<string,int>mp[mx];
vector<int>adj[mx];
vector<pii>qq[mx];
int sub[mx], lvl[mx];
int cnt[mx];
int ans[mx];
bool mark[mx];
int st[mx], en[mx], rev[mx];
int Time;

void dfs( int u, int pre )
{
    st[u]= ++Time;
    lvl[u]= lvl[pre]+1;
    rev[Time]= u;
    sub[u]++;

    for( auto v: adj[u] )
    {
        dfs(v,u);
        sub[u]+= sub[v];
    }

    en[u]= Time;
}

void sack( int u, bool keep )
{
    int boro= 0, bigchild= -1;

    for( auto v: adj[u] )
        if( sub[v]>boro )
            boro= sub[v], bigchild= v;

    for( auto v: adj[u] )
        if( v!=bigchild )
            sack( v, 0 );
    if( bigchild!=-1 )
        sack( bigchild, 1 );

    for( auto v: adj[u] )
        if( v!=bigchild )
            for( int i=st[v]; i<=en[v]; i++ )
                mp[ lvl[ rev[i] ] ][ val[ rev[i] ] ]++;

    mp[ lvl[u] ][ val[u] ]++;

    for( auto q: qq[u] )
        if( q.ff<mx )
            ans[q.ss]= mp[q.ff].size();

    if(!keep)
        for( int i=st[u]; i<=en[u]; i++ )
        {
            mp[ lvl[ rev[i] ] ][ val[rev[i]] ]--;

            if( !mp[ lvl[ rev[i] ] ][ val[rev[i]] ] )
                mp[ lvl[rev[i]] ].erase( val[rev[i]] );
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n;

    for( int i=1; i<=n; i++ )
    {
        int p;
        cin>>val[i]>>p;

        if( p )
            adj[p].push_back(i);
        else
            mark[i]= 1;
    }

    for( int i=1;i<=n;i++ )
        if( mark[i] )
            dfs(i,i);

    cin>>q;

    for( int i=0; i<q; i++ )
    {
        int u,k;
        cin>>u>>k;

        qq[u].push_back( pii(k+lvl[u],i) );
    }

    for( int i=1;i<=n;i++ )
        if( mark[i] )
            sack(i,0);

    for( int i=0; i<q; i++ )
        cout<< ans[i] <<"\n";
}
