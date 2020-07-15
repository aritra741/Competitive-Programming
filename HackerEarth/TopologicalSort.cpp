#include <bits/stdc++.h>
using namespace std;

vector <int> st;
set <int> ind;
set <int> ::iterator it;
vector < int > adj[11];

void topsort(bool vis[], int n,  int current)
{
            vis[current]=1;

    for(int i=0;i<adj[current].size();i++)
    {//cout<<adj[current][i]<<endl;
        if(!vis[adj[current][i]])
        {

            topsort(vis,n, adj[current][i]);

        }
    }
    st.push_back(current);

}

int main()
{
    int n,m;
    cin>>n>>m;
    bool vis[n+1]={0};
    for(int i=0;i<m;i++)
    {
        int p,q;
        cin>>p>>q;
        adj[p].push_back(q);
        sort(adj[p].begin(), adj[p].end());
        ind.insert(p);

    }
    for(it=ind.end();it!=ind.begin();it--)
        topsort(vis, n,  *it);
    reverse(st.begin(), st.end());
    for(int i=0;i<st.size();i++)
        cout<<st[i]<<" ";
}
