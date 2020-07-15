#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int u,v;

    edge( int a, int b )
    {
        u= a;
        v= b;
    }
};

vector<edge>v;
int col[100007], hit[100007], tot;

int main()
{
    int n;
    cin>>n;

    for( int i=1;i<n;i++ )
    {
        int p,q;
        cin>>p>>q;

        v.push_back( edge( p,q ) );
    }

    for( int i=1;i<=n;i++ )
        cin>> col[i];

    for( int i=0;i<n-1;i++ )
    {
        if( col[v[i].u]!=col[v[i].v] )
            tot++, hit[ v[i].u ]++, hit[ v[i].v ]++;
    }

    set<int>st;

    for( int i=1;i<=n;i++ )
        if( hit[i]==tot )
            st.insert( i );

    if( !st.size() )
        cout<<"NO\n";
    else
        cout<<"YES\n"<<*(st.begin())<<"\n";
}
