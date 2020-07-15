#include <bits/stdc++.h>
#define mx 100007
using namespace std;

vector <int> adj[mx];
bool found= 0;

void dfs( int u, int d, int tot )
{
    if(u==d)
    {
        found= 1;
        return;
    }

    int sz= adj[u].size();

    for(int i=0;i<sz;i++)
    {
        int v= adj[u][i];

    }
}

int main()
{
    int n;
    cin>>n;

    string s,t;
    cin>>s>>t;

    map<string, int> stToInt;
    map<int, string> intToSt;

    int cnt=2;

    stToInt[s]=1;
    stToInt[t]=n;
    intToSt[1]=s;
    intToSt[n]=t;

    for(int i=1;i<=n;i++)
    {
        string s1,s2,w;
        cin>>s1>>s2>>w;

        if(!stToInt[s1])
        {
            stToInt[s1]= cnt++;
            intToSt[cnt-1]= s1;
        }

        if(!stToint[s2])
        {
            stToInt[s2]= cnt++;
            intToSt[cnt-1]= s2;
        }

        adj[ stToInt[s1] ].push_back( stToInt[s2] );
        adj[ stToInt[s2] ].push_back( stToInt[s1] );
    }

}
