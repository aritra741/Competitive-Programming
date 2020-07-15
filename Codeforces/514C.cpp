#include<bits/stdc++.h>
using namespace std;
struct data
{
    int tree[3];
    int complete;
}trie[600007];
char text[600007];
int tot_node=1, totlen;

void Insert_trie()
{
    int node=0;
    for(int i=0;text[i];i++){
        int id=(int) (text[i]-'a');
        if(trie[node].tree[id]==0){
            trie[node].tree[id]=++tot_node;
        }
        node=trie[node].tree[id];
    }
    trie[node].complete++;
}

bool dfs( int node, int len, int mis )
{
    if( len==totlen )
    {
        if(trie[node].complete)
        {
            if(mis==1)
                return 1;
            return 0;
        }
        return 0;
    }

    if(mis>1)
        return 0;

    bool ret= 0;

    for( int i=0;i<3;i++ )
    {
        if( trie[node].tree[i] )
        {
            if( text[len]-'a'==i )
                ret|= dfs( trie[node].tree[i], len+1, mis );
            else
                ret|= dfs( trie[node].tree[i], len+1, mis+1 );
        }
    }

    return ret;
}

int main()
{
    int n,q;
    scanf("%d %d", &n, &q);

    for( int i=0;i<n;i++ )
    {
        scanf("%s", text);
        Insert_trie();
    }

    while(q--)
    {
        scanf("%s", text);
        totlen= strlen(text);

        bool ok= dfs( 0, 0, 0 );

        if(ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
