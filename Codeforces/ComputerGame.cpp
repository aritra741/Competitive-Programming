#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int q;
    cin>>q;

    while(q--)
    {
        ll k,n,a,b;
        scanf("%lld %lld %lld %lld", &k, &n, &a, &b);

        if( n*b>=k )
            printf("-1\n");
        else
        {
            ll low= 0;
            ll high= n+1;
            ll mid= (low+high)/2;

            while( high>low+1 )
            {
                mid= (low+high)/2;

                if( a*mid+b*(n-mid)>=k )
                    high= mid;
                else
                    low= mid;
            }

            printf("%lld\n", low);
        }
    }
}
