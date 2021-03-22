#include <bits/stdc++.h>
#define mx 1000007
#define ll long long
using namespace std;

ll sq( ll n )
{
    ll s = sqrt(n);

    if ( (s - 1) * (s - 1) == n )
        return s - 1;
    if ( (s + 1) * (s + 1) == n )
        return s + 1;
    return s;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while (tc--)
    {
        ll x;
        scanf("%lld", &x);

        ll ans = 1;
        int odd= 0, ev= 0;

        ll y= sq(x);

        if(y*y==x)
        {
            for( ll i=2;i*i<=y;i++ )
            {
                int tmp= 0;

                while(y%i==0)
                    y/= 2, tmp++;

                if(tmp&1)
                    odd+= tmp;
                else
                    ev+= tmp;
            }

            if(y>1)
                odd++;

            odd*= 2;
            ev*= 2;

            cout<<odd<<" "<<ev<<endl;
        }

        if(ev>odd)
            printf("Psycho Number\n");
        else
            printf("Ordinary Number\n");
    }
}