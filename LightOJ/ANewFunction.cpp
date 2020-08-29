#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        ll n;
        scanf("%lld", &n);

        ll tot= 0;

        int sq= sqrt(n);
        for(int i=2;i<=sq;i++)
        {
            tot+= (n/i - 1)*i;
        }

        printf("%lld\n", tot);
    }
}
