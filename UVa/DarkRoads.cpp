#include <bits/stdc++.h>
using namespace std;

int par[200007];

struct edge{
    int p,q,w;
}edges[200007];

bool cmp(const edge &a, const edge &b)
{
    return a.w<b.w;
}

int findP( int u )
{
    if(par[u]!=u)
        par[u]= findP( par[u] );
    return par[u];
}

void unionP( int u, int v )
{
    int p= findP( u );
    int q= findP( v );

    par[p]= q;

}

int main()
{
    int n,m;

    while(1)
    {
        scanf("%d %d", &m, &n);
        if(m+n==0)
            break;

        int tot=0;

        for(int i=0;i<n;i++)
        {
            for(int i=0;i<=m;i++)
                par[i]=i;

            int p,q,w;
            scanf("%d %d %d", &p, &q, &w);

            edges[i].p=p;
            edges[i].q=q;
            edges[i].w=w;

            tot+=w;
        }

        sort(edges, edges+n, cmp);

        int mst=0;

        for(int i=0;i<n;i++)
        {
            int a= edges[i].p;
            int b= edges[i].q;
            int c= edges[i].w;

            if( findP(a)!=findP(b) )
            {
                unionP( a,b );
                mst+=c;
            }
        }

        printf("%d\n", tot-mst);

    }


}
