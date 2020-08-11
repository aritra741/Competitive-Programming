#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool mark[70];

int main()
{
    ll u,v;
    cin>>u>>v;

    if(u>v)
        return cout<<"-1", 0;

    if( u==v )
    {
        if(u)
            return cout<<"1"<<endl<<u<<endl,0;
        return cout<<"0", 0;
    }

    vector<int>a,b;

    for( ll i=0;i<63;i++ )
        if(u&(1LL<<i))
            a.push_back(i), mark[i]= 1;

    ll diff= v-u;

    if(diff&1)
        return cout<<"-1", 0;

    diff/= 2;

    vector<int>lagbe;
    int cnt= 2;

    for( int i=0;i<63;i++ )
        if( diff&(1LL<<i) )
        {
            lagbe.push_back(i);

            if( mark[i] )
                cnt= min( cnt+1, 3 );
        }

    ll ansx= 0, ansy= 0, ansz= 0;

    for( int i=0;i<a.size();i++ )
        ansx|= 1LL<<a[i];

    for( auto x: lagbe )
        ansy|= 1LL<<x;

    if(cnt>2)
        for( auto x: lagbe )
            ansz|= 1LL<<x;
    else
        for( auto x: lagbe )
            ansx|= 1LL<<x;

    cout<<cnt<<endl;

    cout<<ansx<<" "<<ansy;

    if(cnt>2)
        cout<<" "<<ansz;
}
