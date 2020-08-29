#include <bits/stdc++.h>
#define MX 70000
using namespace std;

int adj[MX], ind[MX];
int length[MX];
bool vis[MX];
bool exist[MX];
int cnt;
vector <int> v,st;

void initialize(int n)
{
    for(int i=0;i<=n;i++)
        length[i]=-1,exist[i]=0;
}
void topsort(int u)
{
    vis[u]=1;
    if(adj[u] and !vis[adj[u]])
        topsort( adj[u] );
    st.push_back(u);
}

void dfs(int u)
{
    vis[u]=1;
    length[u]=1;
    int p=adj[u];
    if(!vis[p])
        dfs(p);

    length[u]+=length[p];
    vis[u]=0;
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        int n;
        cin>>n;

        vis[0]=1;

        initialize(n);

        for(int i=1;i<=n;i++)
            {
                int p,q;
                scanf("%d %d", &p, &q);
                adj[p]=q;
                exist[p]=exist[q]=1;
            }

        for(int i=1;i<=n;i++)
            if(exist[i] and !vis[i])
                topsort(i);

        memset(vis, 0, sizeof(vis));

        int sz= st.size();
        int mx=-1,ans=60000;

        reverse(st.begin(), st.end());

        for(int i=0;i<sz;i++)
        {
            int u=st[i];
            if(length[u]==-1)
                dfs(u);

            if(length[u]>=mx and u<ans)
                mx=length[u],ans=u;
        }

        printf("Case %d: %d\n", t, ans);

        memset(vis,0, sizeof(vis));

        for(int i=0;i<=n;i++)
            adj[i]=0;
    }
}
