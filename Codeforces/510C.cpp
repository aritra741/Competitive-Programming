#include<bits/stdc++.h>
using namespace std;

vector<int>adj[26];
vector<int> v;
int ind[26];
int vis[26];
bool done[26];
bool cyc= 0;

void dfs( int u )
{
    if(cyc)
        return;

    vis[u]= 1;

    for( int i=0;i<adj[u].size();i++ )
    {
        int v= adj[u][i];
        if( vis[v]==1 )
        {
            cyc= 1;
            return;
        }

        if( vis[v]==0 )
            dfs(v);
    }

    vis[u]= 2;
    v.push_back(u);
}

int main()
{
    int n;
    cin>>n;
    string s[n];

    for( int i=0;i<n;i++ )
        cin>>s[i];

    for( int i=0;i<n-1;i++ )
    {
        int j= 0, k= 0;

        while(s[i][j]==s[i+1][k] and j<s[i].size() and k<s[i+1].size())
            j++, k++;

        if( j<s[i].size() and k<s[i+1].size() )
            adj[s[i][j]-'a'].push_back( s[i+1][k]-'a' ),
            ind[s[i+1][k]-'a']++;
        else if( s[i].size()>s[i+1].size() )
            return cout<<"Impossible\n", 0;
    }

    for( int i=0;i<26;i++ )
        if( !ind[i] )
            dfs(i);

    for( int i=0;i<26;i++ )
        if( !vis[i] )
            dfs(i);

    if(cyc)
        return cout<<"Impossible\n", 0;

    reverse( v.begin(), v.end() );

    for( int i=0;i<v.size();i++ )
        if( !done[ v[i] ] )
            done[v[i]]= 1, cout<<(char)(v[i]+'a');
}
