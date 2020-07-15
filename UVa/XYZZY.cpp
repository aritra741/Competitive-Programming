#include <bits/stdc++.h>
#define mx 100007
using namespace std;

struct edge
{
    int u,v,cost;
};

vector <int> adj[mx];
vector <edge> e;
bool vis[mx];
int val[mx], state[mx];
int dist[mx];
int n;
bool found= 0;
bool cyc= 0;

void clean()
{
    for(int i=0; i<=n; i++)
        adj[i].clear();

    memset(vis, 0, sizeof(vis));
    memset(val, 0, sizeof(val));
    memset(state, 0, sizeof(state));

    e.clear();
    found= 0;
    cyc= 0;
}

void dfs( int x, int tot )
{
    if(tot<=0)
        return;
    if(x==n)
    {
        if(tot>0)
            found= 1;
        return;
    }

    vis[x]= 1;
    int sz= adj[x].size();

    for(int i=0; i<sz; i++)
    {
        int v= adj[x][i];
        if(!vis[v])
            dfs(v, tot+val[v]);
    }
}

void cycle( int u )
{
    if(cyc)
        return;

    state[u]= 1;
    int sz= adj[u].size();

    for(int i=0; i<sz; i++)
    {
        int v= adj[u][i];

        if(state[v]==1)
        {
            cyc= 1;
            return;
        }
        cycle(v);
    }

    state[u]= 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1)
    {
        cin>>n;

        if(n==-1)
            break;

        for(int i=1; i<=n; i++)
        {
            int deg;

            cin>>val[i]>>deg;

            while(deg--)
            {
                int p;
                cin>>p;
                adj[i].push_back(p);
                edge m;
                m.u= i;
                m.v= p;
                m.cost= val[i]+val[p];

                e.push_back(m);
            }

        }

        cycle(1);

        if(!cyc)
        {
            dfs(1, 100);

            if(found)
                cout<<"winnable\n";
            else
                cout<<"hopeless\n";
        }
        else
        {
            bool poss= 1;

            fill( dist, dist+n, INT_MAX );
            int sz= e.size();

            dist[1]= 0;

            for(int i=0; i<n-1; i++)
            {
                for(int j=0; j<sz; j++)
                {
                    int u= e[j].u;
                    int v= e[j].v;
                    int c= e[j].cost;

                    dist[v]= min(dist[v], dist[u]+c);
                }
            }

            for(int i=0; i<sz; i++)
            {
                int u= e[i].u;
                int v= e[i].v;
                int c= e[i].cost;

                if(dist[v]>dist[u]+c)
                {
                    poss= 0;
                    break;
                }
            }

            if(poss)
                cout<<"winnable\n";
            else
                cout<<"hopeless\n";
        }
        clean();
    }
}
