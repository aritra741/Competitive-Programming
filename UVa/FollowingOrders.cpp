#include <bits/stdc++.h>
using namespace std;

set <int> st;
set <int> ::iterator it;
vector <int> adj[26];
bool vis[26];
int indegree[26];
int sz;
vector <int> v;

void allpossible(void)
{
    bool done=1;
    for(it=st.begin(); it!=st.end(); it++)
    {
        int i= (*it);
        if( indegree[i]==0 and !vis[i] )
        {
            vis[i]=1;
            v.push_back(i);

            for(int j=0; j<adj[i].size(); j++)
            {
                indegree[ adj[i][j] ]--;
            }

            allpossible();
            vis[i]=1;
            for(int j=0; j<adj[i].size(); j++)
            {
                indegree[ adj[i][j] ]++;
            }

            v.erase( v.end()-1 );
            done=0;
        }
    }

    if(done)
    {
        for(int i=0; i<v.size(); i++)
            cout<<(char)(v[i]+'a');
        cout<<endl;
        //v.clear();
    }
}

int main()
{
    string s;

    while(getline(cin,s))
    {
        st= set<int>();
        memset( indegree, 0, sizeof(indegree) );
        int sz= s.size();

        for(int i=0; i<sz; i++)
            if(s[i]!=' ')
                st.insert(s[i]-'a');

        string t;

        getline( cin,t );

        t.erase( remove( t.begin(), t.end(), ' ' ), t.end() );

        sz= t.size();

        for(int i=0; i<sz; i+=2)
        {
            adj[ s[i]-'a' ].push_back( s[i+1]-'a' );
            indegree[ s[i+1]-'a' ]++;
        }

        sz= st.size();

        allpossible();
    }
}
