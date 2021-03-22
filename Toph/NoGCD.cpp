#include <bits/stdc++.h>
#define mx 100007
#define ll long long
using namespace std;

ll cnt[(1<<15)+7], tot[(1<<15)+7];
int pr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main()
{
    int tc;
    scanf("%d", &tc);

    for ( int t = 1; t <= tc; t++ )
    {
        int n;
        scanf("%d", &n);

        ll arr[n + 5];

        for ( int i = 1; i <= n; i++ )
        {
            scanf("%lld", &arr[i]);

            int mask = 0;

            for ( int j = 0; j < 15; j++ )
                if (arr[i] % pr[j] == 0)
                    mask |= (1 << j);

            cnt[mask]++;
        }

        for (int i = 0; i < (1 << 15); ++i)
            tot[i] = cnt[i];
        for (int i = 0; i < 15; ++i)
            for (int mask = 0; mask < (1 << 15); ++mask)
            {
                if (mask & (1 << i))
                    tot[mask] += tot[mask ^ (1 << i)];
            }

        ll ans = 0;

        for ( int mask = 0; mask < (1 << 15); mask++ )
        {
            int now = 0;

            for ( int i = 0; i < 15; i++ )
                if ( !(mask & (1 << i)) )
                    now |= (1 << i);

            ans += tot[now] * cnt[mask];

            for ( int i = 0; i < 15; i++ )
            {
                if (!(mask & (1 << i)))
                    continue;

                int ekhon = now | (1 << i);
                ll actual = tot[ekhon] - tot[now];

                ans += actual * cnt[mask];
            }
        }

        printf("%lld\n", ans);

        for ( int i = 0; i < (1<<15)+7; i++ )
            cnt[i] = 0, tot[i] = 0;
    }
}