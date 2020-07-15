#include<bits/stdc++.h>
using namespace std;

set<int>adj[26];
int deg[26], done[26];
bool f;

string ans;

void dfs( int u, int pre )
{
    if(!f)
        return;
    done[u]= 1;
    ans.push_back(u+'a');

    for( auto v: adj[u] )
        if( v!=pre )
        {
            if(!done[v])
                dfs( v, u );
            else
            {
                f= 0;
                break;
            }
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin>>tc;

    while(tc--)
    {
        string s;
        cin>>s;

        for( int i=0;i<26;i++ )
            deg[i]= 0, adj[i].clear(), done[i]= 0;
        ans.clear();

        f= 1;

        for( int i=1;i<s.size();i++ )
        {
            if( adj[ s[i]-'a' ].find( s[i-1]-'a' )!=adj[ s[i]-'a' ].end() )
                continue;

            adj[ s[i]-'a' ].insert( s[i-1]-'a' );
            adj[ s[i-1]-'a' ].insert( s[i]-'a' );

            if( adj[ s[i]-'a' ].size()>=3 )
            {
                cout<<"NO\n";
                f= 0;
                break;
            }
            if( adj[ s[i-1]-'a' ].size()>=3 )
            {
                cout<<"NO\n";
                f= 0;
                break;
            }

            deg[ s[i]-'a' ]++;
            deg[ s[i-1]-'a' ]++;
        }

        if(!f)
            continue;

        for( int i=0;i<26;i++ )
            if( !deg[i] )
                ans.push_back(i+'a');

        for( int i=0;i<26;i++ )
        {
            if( !done[i] and deg[i]==1 )
                dfs(i,i);
        }

//        cout<<ans<<endl;
        if( f and ans.size()==26 )
            cout<<"YES\n"<<ans<<'\n';
        else
            cout<<"NO\n";
    }
}

