#include <bits/stdc++.h>
#define ll long long
#define mx 300007
#define m 998244353LL
using namespace std;

vector<int> adj[mx];
int col[mx];
int col1, col2;
int cnt;
bool valid;
int now= 1;

ll Pow( ll x, ll y )
{
    ll ans= 1LL;

    while(y>0)
    {
        if(y&1)
            ans= (ans%m*x%m)%m;
        x=(x*x)%m;
        y>>=1;
    }

    return ans%m;
}

void dfs(int u)
{
    int sz= adj[u].size();

    for(int i=0; i<sz; i++)
    {
        int v= adj[u][i];

        if(col[v]<now)
        {
            col[v]= (col[u]==now)?now+1:now;
            cnt++;
            if(col[v]==now)
                col1++;
            else
                col2++;
            dfs(v);
        }

        else if(col[v]==col[u])
            valid= 0;
    }
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int n,e;
        scanf("%d %d", &n,&e);

        for(int i=0; i<e; i++)
        {
            int p,q;
            scanf("%d %d", &p, &q);

            adj[p].push_back(q);
            adj[q].push_back(p);
        }

        ll ans= 0;
        valid= 1;

        for(int i=1; i<=n; i++)
        {
            if(col[i]>=now)
                continue;
            col1= 1, col2= 0;
            col[i]= now;
            cnt= 1;
            dfs(i);

            if(!ans and valid ) ans= 1;
            if(!valid)
                break;

            if(cnt==1)
            {
                ans=(ans*3)%m;
                continue;
            }

            ll temp= (Pow( 2LL, col1 ) + Pow( 2LL, col2 ) )%m;

            ans= (ans*temp)%m;
        }

        if(!valid)
            ans= 0;

        printf("%lld\n", ans%m);

        for(int i=0; i<=n; i++)
            if(adj[i].size())
                adj[i].clear();

        now+=2;
    }
}
