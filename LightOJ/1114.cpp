#include<bits/stdc++.h>
using namespace std;

int ans;

int val( char c )
{
    if(c>='a' and c<='z')
        return c-'a';
    return c-'A'+26;
}

struct data
{
    int tree[53];
    int done;

    data(){}

    data( int x )
    {
        for( int i=0;i<53;i++ )
            tree[i]= 0;
        done= 0;
    }

} trie[1000000+7]; /// max length of a word

char text[107], tmp[100007];
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
//        printf("%d %d\n", node, trie[node].tree[id]);
        node=trie[node].tree[id];
    }

    trie[node].done++;
}

int query( int node )
{
    if(!text[0])
        return 1;
    for(int i=0; text[i]; i++)
    {
        int id=val(text[i]);
//        printf("%d %d %d\n", id, node, trie[node].tree[id]);
        if(trie[node].tree[id]==0)
            return 0;
        node=trie[node].tree[id];
    }

    return trie[node].done;
}

void clean( int node )
{
    for( int i=0; i<53; i++ )
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
            totlen= strlen(text);
            if( totlen>2 )
                sort( text+1, text+totlen-1 );
            Insert_trie();
        }

        int m;
        scanf("%d", &m);
        getchar();

        printf("Case %d:\n", t);
        ans= 1;

        while(m--)
        {
            fgets( tmp,100007,stdin );
            totlen= strlen(tmp);
            int i= 0;

            while(i<totlen)
            {
                int cc= 0;
                int j=i;

                for( ;j<totlen;j++ )
                {
                    if( tmp[j]==' ' or tmp[j]=='\n' )
                        break;
                    text[cc++]= tmp[j];
                }
                text[cc]= 0;

                if(cc>2)
                    sort( text+1, text+cc-1 );

                ans*= query( 0 );
                i= j+1;
            }
            printf("%d\n", ans);
            ans= 1;
        }

        ans= 1;
        tot_node= 1;
        clean(0);
    }
}
