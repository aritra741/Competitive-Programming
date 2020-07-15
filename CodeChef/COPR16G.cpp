#include <bits/stdc++.h>
#define ll long long
using namespace std;

/// Chicken McNugget Theorem

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        ll a,b;
        scanf("%lld %lld", &a, &b);

        if( __gcd(a,b)==1 )
            printf("%lld\n", a*b-a-b+1);
        else
            printf("-1\n");
    }
}
