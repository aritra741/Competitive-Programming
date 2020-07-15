#include <bits/stdc++.h>
#define ll long long
#define mx 10000007
#define inf 100000000000000LL
using namespace std;

bool arr[mx];
vector<ll> prime;
vector<ll> dv, dv2;

ll lcm( ll a, ll b )
{
    return (a*b)/__gcd(a,b);
}

ll Pow( ll a, ll b )
{
    ll res= 1;

    while(b>0)
    {
        if(b&1)
            res*=a;
        a*=a;
        b=b>>1;
    }

    return res;
}

void sieve()
{
    arr[0]=arr[1]= 1;
    prime.push_back(2);

    for(ll i=3; i<mx; i+=2)
    {
        if(!arr[i])
        {
            prime.push_back(i);
            for(ll j=i*i; j<mx; j+=i)
                arr[j]= 1;
        }
    }
}

ll getAns( ll a, ll b, ll l )
{
    int sz= prime.size();
    ll rem= l, rema= a, remb= b;
    ll ans= 1;

    for(int i=0; i<sz and prime[i]<=rem; i++)
    {
        ll t= l, t1= a, t2= b;

        if( a%prime[i]==0 or b%prime[i]==0 )
        {
            if(l%prime[i]!=0)
                return inf;

            int cnt= 0, cnt1= 0, cnt2= 0;

            while( t1%prime[i]==0 or t1%prime[i]==0 or t%prime[i]==0 )
            {
                if(t1%prime[i]==0)
                    t1/=prime[i],
                        rema/=prime[i],
                              cnt1++;
                if(t2%prime[i]==0)
                    t2/=prime[i],
                        remb/=prime[i],
                              cnt2++;
                if(t%prime[i]==0)
                    t/=prime[i],
                       rem/=prime[i],
                            cnt++;
            }

            if( cnt1>cnt or cnt2>cnt )
                return inf;
            if(cnt> max(cnt1,cnt2))
                ans*= Pow(prime[i], cnt);
        }
    }

    if(rem>1)
    {
        int c= 0;
        while(l%rem==0)
        {
            l/=rem;
            c++;
        }

        ans*= Pow( rem, c );
    }

    return ans;
}

int main()
{
    sieve();
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        ll a,b,l;
        bool imp= 0;
        scanf("%lld %lld %lld", &a, &b, &l);

        printf("Case %d: ", t);

        ll c= getAns( a,b,l );

        if( c==inf or lcm(a, lcm(b,c) )!=l)
            imp= 1;

        if(imp)
        {
            printf("impossible\n");
            continue;
        }

        printf("%lld\n", c);

    }
}
