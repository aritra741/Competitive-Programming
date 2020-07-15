#include <bits/stdc++.h>
#define pii pair <int, int>
#define mset(x,i) memset( x,i, sizeof(x) )
using namespace std;

vector <pii> adj[110];
int st=-1;
int negs=0;
bool found=0;
int cnt[110];

void dfs(int x, int src)
{
    if(found)
        return;
    int sz=adj[x].size();
    for( int i=0; i<sz; i++ )
    {
        if(found)
            return;
        int v=adj[x][i].first;
        int w=adj[x][i].second;


        if(v!=src)
            {
                if(w<0)
                    negs+=abs(w);
                if(v==st)
                    found=1;
                else
                    dfs(v,x);
            }
        }
    }




int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        mset(cnt, 0);
        getchar();
        st=-1,found=0;
        negs=0;
        int n;
        cin>>n;

        int mx=-1,stmax=0;
        for(int i=0; i<n; i++)
        {
            int p,q,w;
            cin>>p>>q>>w;
            mx=max(mx, max(p,q));

            adj[p].push_back( pii(q,w) );
            adj[q].push_back( pii(p,-w) );

            cnt[p]++;

            if(stmax<cnt[p])
            {
                st=p;
                stmax=cnt[p];
            }
        }

        cout<<"Case "<<t<<": ";

        dfs( st,st );

        int ans1=negs;
        negs=0;

        int temp,fir,sec;

        fir=adj[st][0].first;
        temp=fir;
        adj[st][0].first=adj[st][1].first;
        adj[st][1].first=temp;

        found=0;

        dfs( st,st );

        int ans2=negs;

        cout<<min(ans1,ans2)<<endl;

        for(int i=1;i<=mx;i++)
            adj[i].clear();
    }
}
