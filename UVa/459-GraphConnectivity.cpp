#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <string>
#include <stack>
#include <set>
#include <string>
#include <stdio.h>
using namespace std;
stack <int> sta;
set < int, greater <int> > things;
set < int, greater <int> > ::iterator j;
vector <int> grid[30];
bool vis[30];
int comp=0;
void dfs(int vertex)
{
    comp++;
    sta.push(vertex);
    vis[vertex]=1;
    while(!sta.empty())
    {

        int u=sta.top();
        sta.pop();
        for(int it=0; it<grid[u].size(); it++)
            if(!vis[grid[u][it]])
            {

                vis[grid[u][it]]=1;
                sta.push(u);
                sta.push(grid[u][it]);
            }

    }
}

int main()
{
    memset(vis, 0, sizeof(vis));
    int tc;
    char c1[3],ch;
    cin>>tc;
    getchar();
    while(tc--)
    {
        memset(vis, 0, sizeof(vis));
        cin>>ch;
        while(cin>>c1 && c1[0])
{

            cout<<"YES2"<<endl;
            grid[c1[0]-64].push_back(c1[1]-64);
            grid[c1[1]-64].push_back(c1[0]-64);
            things.insert(c1[0]-64);
            things.insert(c1[1]-64);
        }

        for(j=things.begin(); j!=things.end(); j++)
        {
            if(!vis[*j])
                dfs(*j);
        }

        cout<<comp<<endl;
    }

    return 0;
}
