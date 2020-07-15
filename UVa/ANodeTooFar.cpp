#include <bits/stdc++.h>
#define mx 100007
using namespace std;

vector<int> adj[mx];
int lvl[mx];
bool vis[mx];

void bfs( int x )
{
    queue<int>q;
    q.push(x);
    lvl[x]= 0;

    while(!q.empty())
    {
        int u= q.front();
        vis[u]= 1;
        q.pop();

        for(int i=0;i<adj[u].size();i++)
        {
            int v= adj[u][i];

            if(lvl[u]+1<lvl[v])
            {
                lvl[v]= lvl[u]+1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n;
    int tc= 1;

    while(1)
    {
        cin>>n;

        if(!n)
            break;

        set<int> st;
        set<int> ::iterator it;
        for(int i=0;i<n;i++)
        {
            int p,q;
            cin>>p>>q;
            st.insert(p);
            st.insert(q);
            adj[p].push_back(q);
            adj[q].push_back(p);
        }

        while(1)
        {
            memset( lvl,0x3f,sizeof(lvl) );
            int p,q;
            cin>>p>>q;

            if(!p and !q)
                break;

            bfs(p);
            int cnt= 0;

            for(it=st.begin();it!=st.end();it++)
            {
                int u= *it;

                if(lvl[u]>q or !vis[u])
                    cnt++;
            }

            cout<<"Case "<<tc++<<": "<<cnt<<" nodes not reachable from node "<<p<<" with TTL = "<<q<<".\n";
            memset( vis,0,sizeof(vis) );
        }

        for(it=st.begin();it!=st.end();it++)
            adj[ *it ].clear();
    }
}
