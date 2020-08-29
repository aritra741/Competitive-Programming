#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <list>
#define INF 1e5+7
using namespace std;
int vis[20005];int mx=0;
set < int, greater < int > > things;
set < int, greater < int > > :: iterator i;
char color[20005];
int r=0;
int b=0;
queue < int > qu;
vector < int > node[20005];
vector < int > ::iterator stuff;

void bfs(int vertex)
{
    r=0;b=0;
    qu.push(vertex);
    while(!qu.empty())
        {
            if(qu.front()){
            int u=qu.front();

            qu.pop();if(!vis[u]){
            if(!color[u]){color[u]='r';r++;}
            if(color[u]=='r')
            {
            for(int cou=0;cou<node[u].size();cou++)
                {
                    if(!color[node[u][cou]])
            {

                    color[node[u][cou]]='b';
                    qu.push(node[u][cou]);
                    b++;
            }}
            vis[u]=1;


        }
        else if(color[u]=='b')
            {
            for(int cou=0;cou<node[u].size();cou++)
            {if(!color[node[u][cou]])
            {

                    color[node[u][cou]]='r';
                    qu.push(node[u][cou]);
                    r++;
            }


            } vis[u]=1;}

            }
    }}mx += max(r, b);};

int main()
{
    memset(color, 0, (sizeof(color)-1));
    memset(vis, 0, sizeof(vis));
    color[0]=-1;
    int p,q,t,edge;cin>>t;
    for(int tc=1;tc<=t;tc++)
    {   mx=0;
        things.clear();


        memset(color, 0, (sizeof(color)));
    memset(vis, 0, sizeof(vis));
    color[0]=-1;
        r=0;b=0;
        cin>>edge;


        for(int k=0;k<edge;k++)
            {
                cin>>p>>q;

            node[p].push_back(q);

            node[q].push_back(p);

            things.insert(p);
            things.insert(q);
            }

         for(i=things.begin();i!=things.end();i++)

         {
          if(!vis[*i] && (*i)){

                bfs(*i);



          }}
          cout<<"Case "<<tc<<": "<<mx<<endl;
                    for (i=things.begin(); i!=things.end(); i++)
{
    for (size_t x = 0; x < node[(*i)].size(); x++)
    {
        node[(*i)][x] = 0;
    }
}
}
    return 0;
}
