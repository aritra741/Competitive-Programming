#include<bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
#define sf(x) scanf("%d", &x)
using namespace std;

vector<pii> v;
map<pii,int> mp;

int main()
{
    int n;
    sf(n);

    for(int i=1;i<=n;i++)
    {
        pii p;
        sf(p.f);
        sf(p.s);
        v.push_back(p);
    }

    int m;
    sf(m);

    for( int i=1;i<=m;i++ )
    {
        pii p;
        sf(p.f);
        sf(p.s);

        mp[p]= i;
    }

    int lastid= -5, ans= 0, cnt= 0;

    for( int i=0;i<n;i++ )
    {
        pii p= v[i];

        if( !mp[p] )
            lastid= -5, cnt= 0;
        else
        {
            if( mp[p]==lastid+1 or mp[p]==lastid-1 )
                cnt++;
            else
                cnt= 1;
            ans= max( ans,cnt );
            lastid= mp[p];
        }
    }

    printf("%d\n", ans);
}
