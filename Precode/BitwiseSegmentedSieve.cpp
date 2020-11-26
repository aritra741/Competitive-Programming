#include <bits/stdc++.h>
#define ll long long
#define MAX 46656
#define LMT 216
#define LEN 4830
#define RNG 100032
#define square(x) ((x)*(x))
#define d(x) cout<<x<<endl;
#define mset(x,v) memset(x, v, sizeof(x))
#define chkC(x,n) (x[n>>6] & (1<<((n>>1) & 31)))    ///Check if Composite
#define setC(x,n) (x[n>>6] |= (1<<((n>>1) & 31)))   ///Set as Composite
using namespace std;

ll arr[MAX/64];     ///mark necessary primes
ll segment[RNG/64];
ll prime[LEN];      ///An array filled with primes

void sieve(void)
{
    ll i,j,k;
    for(i=3;i<LMT;i+=2)     ///We'll only need primes till the sqrt of the largest number
    {                       ///In order to mark those primes, the limit of our sieve will be the sqrt of the sqrt of the larger number
        if(!chkC(arr,i))
            for(j=i*i,k=i<<1;j<MAX;j+=k)
                setC(arr, j);
    }

    for(i=3, j=0;i<MAX;i+=2)
        if(!chkC(arr, i))
            prime[j++]=i;
}

int seg_sieve(ll a, ll b)
{
    int cnt=0;
    if(a<=2 and b>=2)
        cnt++;
    if(b<2)
        return 0;
    if(a<3)
        a=3;
    if(!(a&1))
        a++;

    mset(segment,0);

    for(ll i=0;square(prime[i])<=b;i++)
    {
        ll j= prime[i]*((a+prime[i]-1)/prime[i]);
        if( !(j&1))
            j+=prime[i];
        for(ll k=prime[i]<<1;j<=b;j+=k)
            if(j!=prime[i])
                setC(segment,j-a);
    }

    for(ll p=0;p<=b-a;p+=2)
        if(!chkC(segment,p))
                {
                    cnt++;
                }

    return cnt;


}

int main()
{
    sieve();

    int tc;
    scanf("%d",&tc);

    for(int i=1;i<=tc;i++)
    {
        ll a,b;
        scanf("%lld %lld", &a, &b);

        printf("Case %d: %d\n", i, seg_sieve(a,b));
    }
}
