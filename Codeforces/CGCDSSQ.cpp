#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<int,ll> dist, now, ans;
map<int,ll> ::iterator it;

int main()
{
    int n;
    scanf("%d", &n);

    for( int i=0;i<n;i++ )
    {
        now.clear();
        int p;
        scanf("%d", &p);

        for( it=dist.begin();it!=dist.end();it++ )
            now[ __gcd( it->first, p ) ]+= dist[it->first];
        now[p]++;

        for( it=now.begin();it!=now.end();it++ )
            ans[ it->first ]+= (it->second);
        swap( now, dist );
    }

    int q;
    scanf("%d", &q);

    while(q--)
    {
        int p;
        scanf("%d", &p);

        printf("%lld\n", ans[p]);
    }
}
