#include <bits/stdc++.h>
#define mx 30
using namespace std;

int par[mx], d[mx], low[mx], bel[mx];
bool inStack[mx], vis[mx];
int t= 0;
vector<int> adj[mx];
map<string, int> sttoint;
map<int, string> inttost;

void tarjan( int u )
{
    d[u]=low[u]= ++t;
    inStack
    int sz= adj[u].size();

    for(int i=0;i<)
}

int main()
{
    int n,m;

    while(cin>>n>>m)
    {
        int cnt= 0;
        for(int i=0; i<m; i++)
        {
            string s,t;
            cin>>s>>t;

            if( !sttoint[s] )
            {
                sttoint[s]= cnt++;
                inttost[cnt-1]= s;
            }
            if( !sttoint[t] )
            {
                sttoint[t]= cnt++;
                inttost[cnt-1]= t;
            }

            adj[ sttoint[s] ].push_back( sttoint[t] );
        }


    }
}
