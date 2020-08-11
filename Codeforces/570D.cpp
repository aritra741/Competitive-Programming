#include<bits/stdc++.h>
#define mx 500007
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

vector<int>adj[mx];
vector<pii>qq[mx];
int val[mx], sub[mx], lvl[mx];
bitset<27>cnt[mx];
int ans[mx];
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
            {
                if(!cnt[ lvl[ rev[i] ] ][ val[ rev[i] ] ])
                    cnt[ lvl[ rev[i] ] ][ val[ rev[i] ] ]= 1;
                else
                    cnt[ lvl[ rev[i] ] ][ val[ rev[i] ] ]= 0;
            }

    if(cnt[lvl[u]][ val[u] ])
        cnt[ lvl[u] ][ val[u] ]= 0;
    else
        cnt[ lvl[u] ][ val[u] ]= 1;
    int ff= 0;

    for( auto q: qq[u] )
        ans[q.ss]= cnt[q.ff].count()<=1;

    if(!keep)
        for( int i=st[u]; i<=en[u]; i++ )
        {
            if(!cnt[ lvl[ rev[i] ] ][ val[ rev[i] ] ])
                cnt[ lvl[ rev[i] ] ][ val[ rev[i] ] ]= 1;
            else
                cnt[ lvl[ rev[i] ] ][ val[ rev[i] ] ]= 0;
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;

    for( int i=2; i<=n; i++ )
    {
        int p;
        cin>>p;

        adj[p].push_back(i);
    }

    string s;
    cin>>s;

    for( int i=1; i<=n; i++ )
        val[i]= s[i-1]-'a';

    dfs(1,1);

    for( int i=0; i<q; i++ )
    {
        int u,h;
        cin>>u>>h;

        qq[u].push_back( pii(h,i) );
    }

    sack(1,1);

    for( int i=0; i<q; i++ )
        cout<< (ans[i]?"Yes":"No") <<"\n";
}
