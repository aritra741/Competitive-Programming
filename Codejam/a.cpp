#include<bits/stdc++.h>
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define pii pair<int,int>
#define ff first
#define ss second
#define mx 200007
#define inf 1e9
using namespace std;

int n,m,a,b,c;
int lvl[mx],done[mx];
int pp[mx];
int arr[mx];

vector<pii>adj[mx];
int vis[mx],ase[mx];

bool cmp( pii u, pii v )
{
    return done[u.ss]>done[v.ss];
}

void bfs( int x )
{
    queue<int>q;
    lvl[x]= 1;
    vis[x]= 1;
    q.push(x);

    while(!q.empty())
    {
        int u= q.front();
        cout<<x<<" "<<u<<" "<<lvl[u]<<endl;
        q.pop();

        for( auto v: adj[u] )
        {
            if( vis[v.ff]==1 )
                continue;

            vis[v.ff]= 1;
            lvl[v.ff]= lvl[u]+1;
            q.push(v.ff);
        }
    }
}

bool dfs( int u )
{
    vis[u]= 2;
    if( u==b )
        return 1;
    if( lvl[u]>=lvl[b] )
        return 0;
    for( auto v: adj[u] )
    {
        if( vis[v.ff]==2 )
            continue;
        if( dfs(v.ff) )
        {
            done[v.ss]= 1;
            return 1;
        }
    }

    return 0;
}

bool dfs2( int u )
{
    vis[u]= 3;
    if( u==c )
        return 1;
    if( lvl[u]>=lvl[c] )
        return 0;
    for( auto v: adj[u] )
    {
        if( vis[v.ff]==3 )
            continue;
        if( dfs2(v.ff) )
        {
//            cout<<" "<<v.ff<<endl;
            ase[v.ss]= 1;
            return 1;
        }
    }

    return 0;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);

        for( int i=0;i<m;i++ )
            scanf("%d", &pp[i]);

        for( int i=0;i<m;i++ )
        {
            int p,q;
            scanf("%d %d", &p, &q);

            adj[p].push_back(pii(q,i));
            adj[q].push_back(pii(p,i));
        }

        bfs(a);
//        cout<<lvl[b]<<endl;
        bool ab= dfs(a);

        for( int i=1;i<=n;i++ )
            sort( adj[i].begin(), adj[i].end(), cmp );

        for( int i=0;i<=n;i++ )
            lvl[i]= 0, vis[i]= 0;

        bfs(b);
//        cout<<"sadg"<<lvl[c]<<endl;
        bool ok= dfs2(b);

        sort( pp, pp+m );

        ll ans= 0;
        int k= 0;

        for( int i=0;i<m;i++ )
        {
            if( ase[i] )
            {
                ans+= pp[k];

                if( done[i] )
                    ans+= pp[k];

                k++;
            }
        }

        while(k<m)
            ans+= pp[k++];

        printf("%lld\n", ans);

        for( int i=0;i<=n;i++ )
            adj[i].clear(), lvl[i]= 0, vis[i]= 0;
        for( int i=0;i<m;i++ )
            done[i]= ase[i]= 0;
    }
}
