#include<bits/stdc++.h>
using namespace std;

char s[5007];
int g[5007][5007];
int d[2][5007];
int n;

void Man(bool T)
{
    for(int i=0,l=0,r=-1; i<n; i++)
    {
        int k=(i>r)?T:min(d[T][l+r-i+!T],r-i+1);
        while(0<=i-k-!T&&i+k<n&&s[i-k-!T]==s[i+k])
            k++;
        d[T][i]=k--;
        if(i+k>r)
        {
            l=i-k-!T;
            r=i+k;
        }
    }
}

bool isPal( int l, int r )  ///1-based
{
    return (d[((r-l+1)&1)][((r+l-1)>>1)]>=((r-l+2)>>1));
}

int main()
{
    scanf("%s", s);

    n= strlen(s);

    Man(0);
    Man(1);

    for( int i=1; i<=n; i++ )
        for( int j=i; j<=n; j++ )
            if( isPal( i,j ) )
                g[1][j]++,
                g[1][n+1]--,
                g[i+1][j]--,
                g[i+1][n+1]++;

    for( int i=1; i<=n; i++ )
        for( int j=1; j<=n; j++ )
            g[i][j]+= g[i-1][j]+g[i][j-1]-g[i-1][j-1];

    int q;
    scanf("%d", &q);

    while(q--)
    {
        int l,r;
        scanf("%d %d", &l, &r);

        printf("%d\n", g[l][r]);
    }
}
