#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

int dp[65540], col[20][20];
int vis[65540];
int n,P;

struct point
{
    int x,y;
}p[20];

int sign( point p, point q, point r )
{
    int val= (q.y-p.y)*(r.x-q.x)-
            (q.x-p.x)*(r.y-q.y);

    val=-val;

    if(val<0)
        return 1;
    if(val>0)
        return 2;
    return 0;
}

int rec( int mask )
{
    int tot= __builtin_popcount(mask);
    tot= n-tot;

    if(!tot)
        return 0;
    if(tot==1)
        return 1;
    if( vis[mask]==P )
        return dp[mask];

    int ans= inf;

    for(int i=0;i<n;i++)
    {
        if( mask&(1<<i) )
            continue;

        for(int j=i+1;j<n;j++)
        {
            int now= mask|(1<<i);
            if( now&(1<<j) )
                continue;
            now|=(1<<j);
            now|= col[i][j];

            ans= min( ans, 1+rec( now ) );
        }

        break;
    }

    vis[mask]= P;

    return dp[mask]= ans;
}

void init()
{
    for(int i=0;i<16;i++)
        for(int j=0;j<16;j++)
            col[i][j]|= (1<<i),
            col[i][j]|= (1<<j);
}

void clr()
{
    for(int i=0;i<16;i++)
        for(int j=0;j<16;j++)
            col[i][j]= 0;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int t=1;t<=tc;t++)
    {
        init();
        P++;

        scanf("%d", &n);

        for(int i=0;i<n;i++)
            scanf("%d %d", &p[i].x,&p[i].y);

        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                {
                    for(int k=0;k<n;k++)
                        {
                            if(k==j or k==i)
                                continue;
                            if( !sign( p[i],p[j],p[k] ) )
                                col[i][j]|= (1<<k);
                        }
                }

        printf("Case %d: %d\n", t, rec( 0 ) );

        clr();
    }
}
