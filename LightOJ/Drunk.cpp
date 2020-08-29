#include <bits/stdc++.h>
using namespace std;

vector < int > adj[10001];
int vis[10001];
bool flag;

void dfs(int x)
{
    vis[x]=1;
    for(int i=0;i<adj[x].size();i++)
    {
        //cout<<x<<" "<<adj[x][i]<<" "<<vis[adj[x][i]]<<endl;
        //cout<<x<<" "<<adj[x][i]<<endl;
        if( vis[adj[x][i]]==1)
            {
                //cout<<x<<" "<<adj[x][i]<<endl;
                flag=1;
                return;
            }
            if( vis[adj[x][i]]==0 )
        dfs( adj[x][i] );

    }
    vis[x]=2;
}

int main()
{
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        flag=0;
        int edge;
        int cnt=1;
        cin>>edge;

        map <string, int> stToint;
        map <int, string> intTost;
      //  map <string, int> indegree;
      //  map <string, int> ::iterator it;
        queue <int> q;

        for(int i=0;i<edge;i++)
        {
            string p,q;
            cin>>p>>q;
        //    indegree[q]++;
        //   indegree[p]+=0;
            if(stToint[p]==0)
                {
                    stToint[p]=cnt++;
                    intTost[cnt-1]=p;
                }
            if(stToint[q]==0)
                {
                    stToint[q]=cnt++;
                    intTost[cnt-1]=q;
                }
                adj[stToint[p]].push_back( stToint[q] );
        }

//        while(1)
//        {
//            string s;
//            cin>>s;
//            if(s=="0")
//                break;
//            else
//                cout<<stToint[s]<<endl;
//        }

        memset(vis, 0, sizeof(vis));

       // cout<<cnt<<endl;

        for(int i=1;i<cnt;i++)
        {
            if(flag==1)
                break;
            if(vis[i]==0)
                dfs(i);
        }

        if(flag==1)
            printf("Case %d: No\n", t);
        else
            printf("Case %d: Yes\n", t);

        for(int i=0;i<=cnt;i++)
            adj[i].clear();

    }
}
