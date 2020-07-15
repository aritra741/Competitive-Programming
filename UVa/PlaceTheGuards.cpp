#include <bits/stdc++.h>
#define mx 300
using namespace std;

vector<int> adj[mx];
bool vis[mx], col[mx];
int cnt= 0, cnt0= 0, cnt1= 0;
bool poss= 1;

void bfs(int p)
{
    queue <int> q;
    q.push(p);
    col[p]= 0;
    vis[p]= 1;
    cnt0= 1;

    while(!q.empty())
    {
        int u= q.front();
        q.pop();
        if(!poss)
            break;
        int sz= adj[u].size();

        for(int i=0; i<sz; i++)
        {
            int v= adj[u][i];
            //  cout<<v<<endl;
            if(!vis[v])
            {
                vis[v]= 1;
                col[v]= !col[u];
                if(!col[v])
                    cnt0++;
                else
                    cnt1++;
                q.push(v);
            }

            else if( col[v]==col[u] )
            {
                poss= 0;
                break;
            }
        }
    }
    //   cout<<cnt<<endl;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        memset(col, -1, sizeof(col));

        int v,e;
        cin>>v>>e;

        while(e--)
        {
            int p,q;
            cin>>p>>q;
            adj[p].push_back(q);
            adj[q].push_back(p);
        }

        int tot= 0;

        for(int i=0; i<v; i++)
        {
            cnt0= 0, cnt1=0;
            if(!poss)
                break;
            if(!vis[i])
            {
                bfs(i);
                //cout<<cnt<<endl;
                cnt= min(cnt0, cnt1);
                if(!cnt1)
                    tot++;
                else
                    tot+=cnt;
            }
        }

        // cout<<col[0]<<" "<<col[1]<<" "<<col[2]<<" "<<col[3]<<endl;

        if(!poss)
            cout<<"-1\n";
        else
            cout<<tot<<endl;

        memset(vis, 0, sizeof(vis));

        for(int i=0; i<v; i++)
            adj[i].clear();

        cnt= 1;
        poss= 1;
    }
}
