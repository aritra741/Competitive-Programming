#include<bits/stdc++.h>
#define ll long long
using namespace std;

int g[107][107];
int n, m;

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int s;
        scanf("%d", &s);

        int n;
        scanf("%d", &n);

        for( int i=0;i<n;i++ )
        {
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);

            g[a][b]++;
            g[a][d+1]--;
            g[c+1][b]--;
            g[c+1][d+1]++;
        }

        for( int i=1;i<=s;i++ )
            for( int j=1;j<=s;j++ )
                g[i][j]+= g[i-1][j]+g[i][j-1]-g[i-1][j-1];

        for( int i=1;i<=s;i++ )
            for( int j=1;j<=s;j++ )
                if( g[i][j]>1 )
                    g[i][j]= 1;

        for( int i=1;i<=s;i++ )
            for( int j=1;j<=s;j++ )
                g[i][j]+= g[i-1][j]+g[i][j-1]-g[i-1][j-1];

        int a,b,c,d;

        int mx= 0;
        for( int a=1;a<=s;a++ )
            for( int b=1;b<=s;b++ )
                for( int c=a;c<=s;c++ )
                    for( int d=b;d<=s;d++ )
                        if( g[c][d]-g[a-1][d]-g[c][b-1]+g[a-1][b-1]==0 )
                            mx= max( mx, (c-a+1)*(d-b+1) );

        printf("%d\n", mx);

        for( int i=0;i<=s+1;i++ )
            for( int j=0;j<=s+1;j++ )
                g[i][j]= 0;
    }
}

