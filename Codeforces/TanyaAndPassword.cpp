#include <bits/stdc++.h>
using namespace std;

vector<int> undir[62*62+5], dir[62*62+5];
int ind[62*62+5], outd[62*62+5];
bool vis[62*62+5];
int fin;
int final_path[400007];

/// undir is for finding out if the graph is connected
/// dir is for euler path

int Hash( char c )
{
    if( c>='a' and c<='z' )
        return c-'a';
    if( c>='A' and c<='Z' )
        return c-'A'+26;
    return c-'0'+52;
}

void dfs( int u )
{
    vis[u]= 1;

    for( int i=0; i<undir[u].size(); i++ )
    {
        int v= undir[u][i];

        if( vis[v] )
            continue;
        dfs( v );
    }
}

bool connected( int u )
{
    dfs(u);

    for( int i=0; i<62*62; i++ )
    {
        if( !ind[i] or !outd[i] )
            continue;
        if( !vis[i] )
            return 0;
    }

    return 1;
}

void euler_path( int u )
{
    while( !dir[u].empty() )
    {
        int v= dir[u].back();
        dir[u].pop_back();
        euler_path( v );
    }

    final_path[fin++]= u;           /// Push
}

char antihash( int u )
{
    int v= u%62;

    if( u<26 )
        return 'a'+v;
    if( u<52 )
        return 'A'+v-26;
    return '0'+v-52;
}

int main()
{
    int n,src;
    cin>>n;

    for( int i=0; i<n; i++ )
    {
        string s;
        cin>>s;

        int p= Hash( s[0] )*62+Hash( s[1] );
        int q= Hash( s[1] )*62+Hash( s[2] );

        undir[p].push_back(q);
        undir[q].push_back(p);

        ind[q]++, outd[p]++;

        dir[p].push_back(q);
        src= p;
    }

    int cnt1= 0, cnt2= 0;

    for( int i=0; i<62*62; i++ )
    {
        if( !ind[i] and !outd[i] )
            continue;

        if( abs( outd[i]-ind[i] )>1 )
        {
            return cout<<"NO\n", 0;     /// Euler path not possible
        }

        if( outd[i]<ind[i] )
            cnt1++;
        if( outd[i]>ind[i] )
            src= i, cnt2++;
    }

    if( cnt1>1 or cnt2>1 or cnt1!=cnt2 )
        return cout<<"NO\n", 0;         /// Euler path not possible

    if( !connected(src) )
        return cout<<"NO\n", 0;         /// Euler path not possible

    cout<<"YES\n";
    euler_path(src);

    reverse( final_path, final_path+fin );

    cout<< antihash( final_path[0]/62 );

    for( int i=0;i<fin;i++ )
        cout<< antihash( final_path[i]%62 );
}
