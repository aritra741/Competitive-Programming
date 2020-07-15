#include <bits/stdc++.h>
#define mx 20007
using namespace std;

int par[mx];

int Find( int u )
{
    if(par[u]==u)
        return u;
    return Find( par[u] );
}

void con( int u, int v )
{
    int paru= Find(u);
    int parv= Find(v);

 //   cout<<par[u]<<" "<<par[v]<<endl;

    if(paru == parv)
        cout<<"YES\n";
    else
        cout<<"NO\n";

}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        memset(par, -1, sizeof(par));

        int n,k;
        cin>>n>>k;
        cout<<"Case #"<<t<<":\n";

        for(int i=1; i<=n; i++)
        {
            int p;
            cin>>p;

            if(p)
                par[i]= p;
            else
                par[i]= i;
        }

        while(k--)
        {
            char c;
            cin>>c;

            if(c=='C')
            {
                int p;
                cin>>p;
                par[p]= p;
               // cout<<par[p]<<endl;
            }

            else
            {
                int p,q;
                cin>>p>>q;

                con(p,q);
            }
        }

    }
}
