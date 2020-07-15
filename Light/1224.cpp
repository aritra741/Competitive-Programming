#include<bits/stdc++.h>
using namespace std;

int ans;

int val( char c )
{
    if(c=='A')
        return 0;
    if(c=='C')
        return 1;
    if(c=='T')
        return 2;
    if(c=='G')
        return 3;
}

struct data
{
    int tree[4];
    int hit;

    data(){}

    data( int x )
    {
        for( int i=0;i<4;i++ )
            tree[i]= 0;
        hit= 0;
    }

} trie[1000010]; /// max length

char text[55];
int tot_node=1, totlen;

void Insert_trie()
{
    int node=0;
    for(int i=0; text[i]; i++)
    {
        int id=val(text[i]);

        if(trie[node].tree[id]==0)
        {
            trie[node].tree[id]=tot_node++;
        }
        node=trie[node].tree[id];
        trie[node].hit++;
    }
}

void dfs( int node, int len )
{
    ans= max( ans, trie[node].hit*len );

    for( int i=0; i<4; i++ )
        if( trie[node].tree[i] )
            dfs( trie[node].tree[i], len+1 );
}

void clean( int node )
{
    for( int i=0; i<4; i++ )
        if( trie[node].tree[i] )
            clean( trie[node].tree[i] );

    trie[node]= data(0);
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for( int t=1; t<=tc; t++ )
    {
        int n;
        scanf("%d", &n);

        for( int i=0; i<n; i++ )
        {
            scanf("%s", text);
            Insert_trie();
        }

        dfs(0,0);

        printf("Case %d: %d\n", t, ans);

        ans= 0;
        tot_node= 1;
        clean(0);
    }
}
