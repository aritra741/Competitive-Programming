#include <bits/stdc++.h>
#define mx 100007
using namespace std;

int sz[mx], par[mx];
int ans;

int Find( int u )
{
    if(par[u]==u)
        return u;
    return par[u]= Find(par[u]);
}

void Union( int u, int v )
{
    int paru= Find(u);
    int parv= Find(v);

    if(paru==parv);

    else if( sz[parv]>sz[paru] )
    {
        par[paru]= parv;
        sz[parv]+=sz[paru];
    }

    else
    {
        par[parv]= paru;
        sz[paru]+=sz[parv];
    }

    ans= max( sz[par[u]], sz[par[v]] );
}

void init()
{
    for(int i=1; i<=mx; i++)
        par[i]= i,
        sz[i]= 1;
    ans= -1;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        init();
        int n;
        cin>>n;

        map<string, int> sttoint;
        int cnt= 1;

        for(int i=0; i<n; i++)
        {
            ans= -1;

            string s,t;
            cin>>s>>t;

            if( !sttoint[s] )
                sttoint[s]= cnt++;
            if( !sttoint[t] )
                sttoint[t]= cnt++;

            Union( sttoint[s], sttoint[t] );
            cout<<ans<<endl;
        }


    }
}
