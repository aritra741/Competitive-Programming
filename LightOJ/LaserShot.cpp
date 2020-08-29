#include <bits/stdc++.h>
#define ll long long
#define inf 1000000
#define pdd pair<double,double>
using namespace std;

struct point
{
    ll x,y;
} p[1000];

double getslope( point a, point b )
{
    if(a.y==b.y)
        return inf;
    return ((double)(a.x-b.x)/(double)(a.y-b.y));
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        int n;
        scanf("%d", &n);

        for(int i=0; i<n; i++)
            scanf("%lld %lld", &p[i].x, &p[i].y);

        if(n<3)
        {
            printf("Case %d: %d\n", t, n);
            continue;
        }

        int ans= 0;

        for(int i=0; i<n; i++)
        {
            map<double, int> mp;
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    continue;

                double m= getslope( p[i], p[j] );
                mp[m]++;

                ans= max( ans, mp[ m ]+1 );
            }

        }

        printf("Case %d: %d\n", t, ans);
    }
}

