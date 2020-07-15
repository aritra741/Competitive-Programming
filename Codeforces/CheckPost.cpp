#include <bits/stdc++.h>
#define ll long long
#define mx 100007
#define inf 10000000000000000LL
#define mod 1000000007
using namespace std;

vector<int> adj[mx];
bool vis[mx], instck[mx];
int d[mx], low[mx];
ll cost[mx];
int Time= 0;
stack<int> st;
ll ans= 0;
ll ways= 1;

void tarjan(int u)
{
    vis[u]= 1;
    d[u]=low[u]=++Time;
    st.push(u);
    instck[u]= 1;
    int sz= adj[u].size();

    for(int i=0;i<sz;i++)
    {
        int v= adj[u][i];

        if( !vis[v] )
        {
            tarjan(v);
            low[u]= min( low[u], low[v] );
        }

        else if(instck[v])
        {
            low[u]= min( low[u], d[v] );
        }
    }

    if( d[u]==low[u] )
    {
        vector<ll> perm;

        ll mn= inf;
        while( !st.empty() and st.top()!=u )
        {
            int p= st.top();
            st.pop();
            perm.push_back(cost[p]);
            instck[p]= 0;
            mn=min(mn,cost[p]);
        }

        if( st.top()==u )
        {
            st.pop();
            perm.push_back(cost[u]);
            instck[u]= 0;
            mn=min(mn,cost[u]);
        }

        ans+=mn;

        sort(perm.begin(),perm.end());

        ll tot= upper_bound( perm.begin(),perm.end(),perm[0] )-
                lower_bound( perm.begin(),perm.end(),perm[0] );
        ways=(ways%mod*tot%mod)%mod;
    }
}

int main()
{
    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
        cin>>cost[i];

    int m;
    cin>>m;

    while(m--)
    {
        int p,q;
        cin>>p>>q;

        adj[p].push_back(q);
    }

    for(int i=1; i<=n; i++)
        if(!vis[i])
            tarjan(i);

    cout<<ans<<" "<<ways<<endl;
}
