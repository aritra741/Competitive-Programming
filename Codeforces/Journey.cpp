#include <bits/stdc++.h>
#define MX 100007
using namespace std;

int vis[MX];
vector <int> adj[MX];
int reach[MX];
double ans=0;

void dfs(int u, double dv)
{
    vis[u]=1;

    int sz= adj[u].size();
    stack <int> st;

    for(int i=0;i<sz;i++)
        {
            int v=adj[u][i];
            if(!vis[v])
                {
                    st.push(v);
                }
        }
    int stsz=st.size();
    double send= dv*stsz;
    while(!st.empty())
        {int v=st.top();
        st.pop();
        dfs(v, send);
        }

    if(u!=1)
        ans+= (1/dv);
}

int main()
{
    int n;
    cin>>n;

    n--;

    while(n--)
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    int sz=adj[1].size();

    dfs(1, 1.0);

    cout<<setprecision(10)<<fixed<<ans<<endl;




}
