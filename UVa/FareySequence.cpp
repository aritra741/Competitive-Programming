#include <bits/stdc++.h>
#define ll long long
#define MX 1000007
using namespace std;

bool arr[MX];
int sz;
vector <int> prime;

void sieve()
{
    arr[0]=arr[1]=1;

    prime.push_back(2);

    for(ll i=3; i<MX; i+=2)
    {
        if(!arr[i])
        {
            prime.push_back(i);
            for(ll j=i*i; j<MX; j+=i*2)
                arr[j]=1;
        }
    }

}

ll ans[MX];

void pre()
{
    ans[0]=0;
    sz= prime.size();

    for(int i=1; i<MX; i++)
    {
        double cnt=i;
        int temp= i;
        int sq= sqrt( temp );

        for(int j=0; j<sz and prime[j]<=sq; j++)
        {
            if(temp%prime[j]==0)
            {
               // cout<<i<<" "<<temp<<endl;
                cnt*= (1.0-(1.0/(double)prime[j]));
                while( temp%prime[j]==0 )
                {
                    temp/=prime[j];
                }
            }
        }

        if(temp!=1)
            cnt*= (1.0-(1.0/(double)temp));

//        if(i<10)
//            cout<<cnt<<endl;

        ans[i]= ans[i-1]+(ll)cnt;
    }
}

int main()
{
    sieve();
    pre();

    ll n;

    while(1)
    {
        scanf("%lld", &n);

        if(!n)
            break;

        printf("%lld\n", ans[n]-1);
    }
}

