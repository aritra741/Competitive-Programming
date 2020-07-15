#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int, int> pii;
int main()
{
    ll n,m;
    cin>>n>>m;
    vector <pii> fin(n);
    for(int i=0;i<n;i++)
        {
            cin>>fin[i].first;
            fin[i].second=i;
        }
    int p,q;
    vector <int> adj[n];

//    bool vis[n];
//    memset(vis, 0, sizeof(vis));
    int org[n];
    memset(org, 0, sizeof(org));
    for(int i=0;i<m;i++)
    {
       // cout<<"YES1"<<endl;
        cin>>p>>q;
        p--;
        q--;
        adj[p].push_back(q);
        adj[q].push_back(p);
       // cout<<"YES2"<<endl;
//        if(vis[p-1]==0)
//        {
//            vis[p-1]=1;
//            fin[p-1].first=0;
//        }
//        if(vis[q-1]==0)
//        {
//            vis[q-1]=1;
//            fin[q-1].first=0;
//        }

        org[p]+=fin[p].first;
        org[q]+=fin[q].first;
//        cout<<fin[p-1].first<<" moop"<<endl;
//        cout<<fin[q-1].first<<" moop"<<endl;
        //fin[p-1].second=p;
        //fin[q-1].second=q;
        //cout<<"q-1= "<<q-1<<endl;
       // cout<<"First "<<org[p-1]<<endl;;


    }
    sort(fin.begin(), fin.end());
    ll ans=0;
    //cout<<fin[0].first<<endl;
    for(int i=0;i<=n-1;i++)
        {
            ans+=org[fin[i].second];

            //cout<<fin[i].first<<" ";
            for(int j=0;j<adj[fin[i].second].size();j++)
            {
                //cout<<adj[fin[i].second][j]<<" ";
                org[adj[fin[i].second][j]]-=fin[i].first;
            }
            //cout<<endl;cout<<"ans "<<ans<<endl;
        }
    cout<<ans;
}
