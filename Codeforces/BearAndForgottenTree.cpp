#include <bits/stdc++.h>
using namespace std;

vector<int> adj[300007], con;
set<int> unv,unv2;
set<int> ::iterator it;
bool valid= 1;
int cnt,n,m,k;

void bfs( int x )
{
    unv.erase(x);
    queue<int>q;
    q.push(x);

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        vector<int> temp;

        for( it= unv.begin(); it!=unv.end(); it++ )
        {
            int v= (*it);

            if( !binary_search( adj[u].begin(),adj[u].end(),v ) )
            {

                if(u==1)
                    con.push_back(v);

                temp.push_back(v);
                q.push(v);
            }
        }

        for(int i=0; i<temp.size(); i++)
            unv.erase(temp[i]);
    }
}

void bfs2( int x )
{
    unv2.erase(x);
    queue<int>q;
    q.push(x);

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        vector<int> temp;

        for( it= unv2.begin(); it!=unv2.end(); it++ )
        {
            int v= (*it);

            if( !binary_search( adj[u].begin(),adj[u].end(),v ) )
            {
                temp.push_back(v);
                q.push(v);
            }
        }

        for(int i=0; i<temp.size(); i++)
            unv2.erase(temp[i]);
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);

    while(m--)
    {
        int p,q;
        scanf("%d %d", &p,&q);

        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    if( adj[1].size()==n-1 )
    {
        printf("impossible\n");
        return 0;
    }

    for(int i=1; i<=n; i++)
        unv.insert(i),
        unv2.insert(i),
        sort( adj[i].begin(), adj[i].end() );

    for(int i=1; i<=n; i++)
    {
        if( unv.find(i)==unv.end() )
            continue;

        if(i!=1)
        {
            valid= 0;
            break;
        }

        bfs(i);
    }

    if(!valid)
    {
        printf("impossible\n");
        return 0;
    }

    unv2.erase(1);

    for(int i=0; i<con.size(); i++)
    {
        if( unv2.find(con[i])==unv2.end() )
            continue;

        cnt++;
        bfs2(con[i]);
    }

    int d= n-1-adj[1].size();

    if( k>=cnt and k<=d )
        printf("possible\n");
    else
        printf("impossible\n");
}
