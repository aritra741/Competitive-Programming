#include <bits/stdc++.h>
using namespace std;

bool arr[1007];
vector<int> adj[1007];

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<n;i++)
    {
        int p;
        cin>>p;
        arr[p]= 1;
        adj[p].push_back( i+1 );
    }

    bool valid= 1;

    for(int i=1;i<=n and valid;i++)
    {
        if( !arr[i] )
            continue;
        if(adj[i].size()<3)
        {
            valid= 0;
            break;
        }

        int cnt= 0;

        for(int j=0;j<adj[i].size();j++)
        {
            int v= adj[i][j];
            if( !arr[v] )
                cnt++;
        }

        if(cnt<3)
            valid= 0;
    }

    if(valid)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}
