#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> adj[110];
map<ll, bool> vis;
map<ll, ll> mp, Back;
vector<ll> ans;
int ind[110];

void dfs( ll u )
{
    vis[u]= 1;
    ans.push_back(u);

    for(int i=0; i<adj[u].size(); i++)
    {
        ll v= adj[u][i];

        if(vis[v])
            continue;

        dfs(v);
    }
}

int main()
{
    int n;
    cin>>n;

    ll arr[n];

    for(int i=0; i<n; i++)
        cin>>arr[i],
        mp[arr[i]]= i,
        Back[i]= arr[i];

    for(ll i=0; i<n; i++)
        for(ll j=i+1; j<n; j++)
        {
            if( arr[i]%arr[j]==0 and arr[i]/arr[j]==3 )
                adj[mp[arr[i]]].push_back(mp[arr[j]]), ind[j]++;
            else if( arr[j]%arr[i]==0 and arr[j]/arr[i]==3 )
                adj[mp[arr[j]]].push_back(mp[arr[i]]), ind[i]++;
            else if( arr[j]%arr[i]==0 and arr[j]/arr[i]==2 )
                adj[mp[arr[i]]].push_back(mp[arr[j]]), ind[j]++;
            else if( arr[i]%arr[j]==0 and arr[i]/arr[j]==2 )
                adj[mp[arr[j]]].push_back(mp[arr[i]]), ind[i]++;
        }

    int idx= 0;
    for(int i=0;i<n;i++)
        if( !ind[i] )
            idx= i;

    dfs(mp[arr[idx]]);

    for(int i=0;i<ans.size();i++)
        cout<< Back[ans[i]] <<" ";
    cout<<endl;
}
