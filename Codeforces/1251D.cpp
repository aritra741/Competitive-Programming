#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define ff first
#define ss second
#define mx 200007
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

ll arr[mx];

bool cmp( pii x, pii y )
{
    return x.ss < y.ss;
}

int main()
{
    fast;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        ll s;

        cin >> n >> s;

        pii arr[n + 5];

        for ( int i = 0; i < n; i++ )
            cin >> arr[i].ff >> arr[i].ss;

        sort( arr, arr + n, cmp );
        ll r = arr[n / 2].ss;
        sort( arr, arr + n );
        ll l = arr[n / 2].ff, ans= l;

        while (l <= r)
        {
            ll mid = (l + r) / 2;
            ll rem = s;

            std::vector<pii> v;

            int cnts = 0, cntb = 0;
            for ( int i = 0; i < n; i++ )
            {
                if ( arr[i].ff > mid )
                    cntb++, rem -= arr[i].ff;
                else if ( arr[i].ss < mid )
                    cnts++, rem -= arr[i].ff;
                else
                    v.push_back(arr[i]);
            }

            if ( cnts > n / 2 or cntb > n / 2 )
            {
                r = mid - 1;
                continue;
            }

            sort( v.begin(), v.end(), greater<pii>() );

            for ( int i = (int)v.size() - 1; i >= 0; i-- )
            {
                pii x = v[i];
                if ( cnts < n / 2 )
                {
                    rem -= x.ff;
                    cnts++;
                    v.pop_back();
                }
                else if ( cntb < n / 2 )
                {
                    rem -= mid;
                    cntb++;
                    v.pop_back();
                }
            }

            if ( v.size() )
            {
                rem -= mid;
                v.pop_back();
            }
            else
            {
                r = mid - 1;
                continue;
            }
            if ( rem < 0 or cnts < n / 2 or cntb < n / 2 )
                r = mid - 1;
            else
                ans = mid, l = mid + 1;
        }

        cout << ans << "\n";
    }
}
