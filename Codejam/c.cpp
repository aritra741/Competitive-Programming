#include<bits/stdc++.h>
#define sf(x) scanf("%d", &x)
using namespace std;

struct node
{
    int st, en, id;

    node( int a, int b, int c )
    {
        st= a;
        en= b;
        id= c;
    }
};

int col[1007];
vector<int>adj[1007];
vector<node>v;

bool bfs( int u )
{
    bool f= 1;
    for( auto x: adj[u] )
    {
        if( !col[x] )
        {
            if( col[u]==1 )
                col[x]= 2;
            else
                col[x]= 1;

            f&= bfs(x);
        }
        else if( col[x]==col[u] )
            return 0;
    }

    return f;
}

int main()
{
    int tc;
    sf(tc);

    for( int t=1; t<=tc; t++ )
    {
        int n;
        sf(n);

        for( int i=0; i<n; i++ )
        {
            int a,b;
            sf(a);
            sf(b);

            v.push_back( node( a,b,i ) );
        }

        for( int i=0; i<n; i++ )
            for( int j=i+1; j<n; j++ )
            {
                if( v[i].en<=v[j].st or v[j].en<=v[i].st );
                else
                    adj[i].push_back(j),
                        adj[j].push_back(i);
            }

        bool f= 1;
        for( int i=0; i<n; i++ )
            if( !col[i] )
            {
                col[i]= 1;

                if( !bfs(i) )
                {
                    f= 0;
                    break;
                }
            }

        printf("Case #%d: ", t);

        if(!f)
            printf("IMPOSSIBLE");
        else
            for( int i=0; i<n; i++ )
            {
                if( col[i]==1 )
                    printf("C");
                else
                    printf("J");
            }

        printf("\n");

        for( int i=0;i<n;i++ )
            adj[i].clear(), col[i]= 0;
        v.clear();
    }
}
