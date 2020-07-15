#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>
#include<complex>
#define mx 50007
using namespace std;

struct data
{
    int tree[28];
    int complete;

    data()
    {
        complete= 0;
    }

} trie[mx];

int n;
char text[25];
int tot_node;

int Insert_trie()
{
    int node=0;
    for(int i=0; text[i]; i++)
    {
        int id=(int) (text[i]-'a');
        if(trie[node].tree[id]==0)
        {
            trie[node].tree[id]=++tot_node;
        }
        node=trie[node].tree[id];
    }
    if(!trie[node].complete)
        trie[node].complete= ++n;

    return trie[node].complete;
}

int Search_Trie()
{
    int node=1;
    for(int i=0; text[i]; i++)
    {
        int id=(int) (text[i]-'a');
        if(trie[node].tree[id]==0)
            return 0;
        node=trie[node].tree[id];
    }
    return trie[node].complete;
}

void init()
{
    for( int i=0;i<mx;i++ )
        par[i]= i, Size[i]= 1;
}

int main(int argc, char const *argv[])
{
    init();

    vector<int> nodes;

    while(scanf("%s",text)==1)
    {
        int u= Insert_trie();
        scanf("%s",text);
        int v= Insert_trie();

        unite(u,v);

        deg[u]++, deg[v]++;
    }

    int cnt= 0;
    for( int i=1;i<=n;i++ )
        if( Find(i)==i )
            cnt++;

   // cout<<cnt<<endl;
    if(cnt>1)
        return cout<<"Impossible\n", 0;

    int odd= 0;
    for( int i=1;i<=n;i++ )
        if( deg[i]&1 )
            odd++;

    if( odd==0 or odd==2 )
        printf("Possible\n");
    else
        printf("Impossible\n");
}
