#include <bits/stdc++.h>
#define mx 100007
#define ll long long
using namespace std;

bool arr[mx];

void sieve()
{
    arr[0]=arr[1]=1;

    int sq= sqrt(mx);

    for(ll i=2; i<=sq; i++)
    {
        if(!arr[i])
            for(ll j=i*i; j<mx; j+=i*2)
                arr[j]=1;
    }
}

ll bigmod( ll x, ll y, ll m )
{
    ll res=1;

    while(y>0)
    {
        if(y&1)
            res= (res%m*x%m)%m;
        y>>=1;
        x= (x%m*x%m)%m;
    }

    return res%m;
}

int main()
{
    sieve();

    while(1)
    {
        int n;
        scanf("%d", &n);

        if(!n)
            break;

        if( !arr[n] )
        {
            printf("%d is normal.\n", n);
            continue;
        }

        bool flag=0;

        for(int i=2; i<n; i++)
        {
            if(__gcd( i,n )==1)
            {
                   // cout<<bigmod((ll)i,(ll)(n-1), n)<<endl;
                if( bigmod((ll)i,(ll)(n-1), n)!=1 )
                {
                    printf("%d is normal.\n", n);
                    flag=1;
                    break;
                }
            }
        }

        if(!flag)
            printf("The number %d is a Carmichael number.\n", n);
    }
}
