#include<bits/stdc++.h>
#define pii pair<int,int>
#define piii pair<int,pii>
#define ff first
#define ss second
#define mx 200007
using namespace std;

int ind[mx], st[mx], lvl[mx], num;
vector<int>adj[mx];
vector<piii>ed;

bool cyc;

void dfs( int u )
{
    st[u]= 1;

    for( auto v: adj[u] )
    {
        if(st[v]==2)
            continue;

        if( st[v]==1 )
        {
            cyc= 1;
            return;
        }

        dfs( v );
    }

    lvl[u]= ++num;
    st[u]= 2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,m;
        cin>>n>>m;

        cyc= 0;
        num= 0;
        ed.clear();

        for( int i=1;i<=n;i++ )
        {
            ind[i]= 0;
            st[i]= 0;
            lvl[i]= 0;
            adj[i].clear();
        }

        for( int i=0;i<m;i++ )
        {
            int t,u,v;
            cin>>t>>u>>v;

            if(t)
                adj[u].push_back(v), ind[v]++;
            ed.push_back( piii(t,pii(u,v)) );
        }

        queue<int> q;
        int num= 0;

        for(int i=1; i<=n; i++)
            if(!st[i])
                dfs(i);

        if(cyc)
        {
            cout<<"NO\n";
            continue;
        }

        cout<<"YES\n";

        for( int i=0;i<m;i++ )
        {
            piii pp= ed[i];

            int u= pp.ss.ff;
            int v= pp.ss.ss;
            int tp= pp.ff;

            if(tp)
            {
                cout<<u<<" "<<v<<"\n";
                continue;
            }

            if( lvl[u]<=lvl[v] )
                cout<<v<<" "<<u<<"\n", ind[u]++;
            else
                cout<<u<<" "<<v<<"\n", ind[v]++;
        }


    }
}
