#include<bits/stdc++.h>
#define ll long long
using namespace std;

set<ll>row,col;

int main()
{
    ll n,m;
    cin>>n>>m;

    ll ans= n*n;

    while(m--)
    {
        ll p,q;
        cin>>p>>q;

        bool attacked= 0;

        if( row.find(p)!=row.end() )
            attacked= 1;
        else
        {
            ans-= n-1-col.size();

            if(col.find(q)!=col.end())
                ans--;
        }

        if( col.find(q)!=col.end() )
            attacked= 1;
        else
        {
            ans-= n-1-row.size();
            if(row.find(p)!=row.end())
                ans--;
        }
        if(!attacked)
            ans--;

        row.insert(p);
        col.insert(q);

        cout<<ans<<" ";
    }
}
