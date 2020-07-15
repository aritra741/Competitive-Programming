#include<bits/stdc++.h>
#define mx 200007
using namespace std;

int par[mx], Size[mx];
vector<int>v[27];

int Find( int u )
{
    if( u==par[u] )
        return par[u];
    return par[u]= Find( par[u] );
}

void unite( int u, int v )
{
    int paru= Find( u );
    int parv= Find( v );

    if(paru!=parv)
    {
        if( Size[paru]>Size[parv] )
            Size[paru]+= Size[parv], par[parv]= paru;
        else
            Size[parv]+= Size[paru], par[paru]= parv;
    }
}

void init()
{
    for( int i=0;i<mx;i++ )
        par[i]= i, Size[i]= 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();

    int n;
    cin>>n;

    for( int i=0;i<n;i++ )
    {
        vector<bool>vis(27,0);

        string s;
        cin>>s;

        for( int j=0;j<s.size();j++ )
            if( !vis[s[j]-'a'] )
                v[ s[j]-'a' ].push_back( i ), vis[ s[j]-'a' ]= 1;
    }

    for( int i=0;i<26;i++ )
        for( int j=1;j<v[i].size();j++ )
            unite( v[i][j], v[i][j-1] );

    int ans= 0;

    for( int i=0;i<n;i++ )
        if( Find(i)==i )
            ans++;

    cout<< ans <<'\n';
}
