#include <bits/stdc++.h>
#define pii pair<int,int>
#define sf(x) scanf("%d", &x)
#define f first
#define s second
using namespace std;

int main()
{
    int tc;
    sf(tc);

    while(tc--)
    {
        int n;
        sf(n);

        pii arr[n];
        int q[n];

        int ans= -2e9;

        for( int i=0;i<n;i++ )
            sf(arr[i].f),
            sf(arr[i].s),
            sf(q[i]),
            ans= max( ans, q[i] );

        map<pii,int> mp;

        for( int i=0;i<n;i++ )
        {
            mp.clear();

            for( int j= 0;j<n;j++ )
            {
                if(i==j)
                    continue;

                int upor= arr[j].s-arr[i].s;
                int nich= arr[j].f-arr[i].f;

                int g= __gcd( upor, nich );

                upor/= g;
                nich/= g;

                mp[pii(upor,nich)]+= q[j];
              //  cout<<i<<" "<<j<<" "<<upor<<" "<<nich<<" "<<mp[pii(upor,nich)]+q[i]<<endl;
            }

            for( auto x: mp )
                ans= max( ans, x.s+q[i] );
        }

        if(ans<0)
            ans= 0;

        printf("%d\n", ans);
    }
}


