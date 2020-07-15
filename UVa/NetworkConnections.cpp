#include <bits/stdc++.h>
#define mx 100007
using namespace std;

int par[mx], sz[mx];

void init( int n )
{
    for(int i=0; i<=n; i++)
        par[i]= i,
        sz[i]= 1;
}

int Find(int u)
{
    if(par[u]==u)
        return u;
    return par[u]= Find( par[u] );
}

void Union( int u, int v )
{
    int paru= Find(u);
    int parv= Find(v);

    if( paru==parv )
        return;

    if( sz[paru]<sz[parv] )
    {
        par[paru]= parv;
        sz[parv]+=sz[paru];
    }

    else
    {
        par[parv]= paru;
        sz[paru]+=sz[parv];
    }

}

bool iscon( int u, int v )
{
    int p= Find(u);
    int q= Find(v);

    if(p==q)
        return 1;
    return 0;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n, yes=0, no=0;
        cin>>n;

        init(n);

        string s;
        getline(cin, s);

        while(1)
        {
            getline(cin, s);

            if(s.empty())
                break;

            stringstream ss;
            ss<<s;

            char c;
            int p,q;
            ss>>c>>p>>q;

            if(c=='c')
            {
                Union(p,q);
            }

            else
            {
                bool ans= iscon(p,q);
                if(ans)
                    yes++;
                else
                    no++;
            }
        }

        cout<<yes<<","<<no<<endl;

        if(tc)
            cout<<endl;
    }
}






