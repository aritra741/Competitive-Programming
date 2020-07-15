#include<bits/stdc++.h>
using namespace std;

int vv[25];

int main()
{
    int n,m;

    while( scanf("%d %d", &n, &m)==2 and n and m )
    {
        for( int i=1;i<=n;i++ )
        {
            int p;
            scanf("%d", &p);

            vv[i]+= p;
        }
        for( int i=0;i<m;i++ )
        {
            int p,q,w;
            scanf("%d %d %d", &p, &q, &w);

            vv[p]-= w;
            vv[q]+= w;
        }

        bool f= 1;
        for( int i=1;i<=n;i++ )
            if( vv[i]<0 )
                f= 0;

        if(f)
            printf("S\n");
        else
            printf("N\n");

        memset( vv,0, sizeof(vv) );
    }
}
