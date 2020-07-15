#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool arr[1000005];
vector <ll> primes;

void sieve(void)
{
    arr[0]=1,arr[1]=1;

    for(ll i=2;i<=100000;i++)
    {
        if(!arr[i])
        {
            primes.push_back(i);
            for(ll j=i*i;j<=1000000;j+=i)
                arr[j]=1;
        }
    }

}

int main()
{
    sieve();
    int sz=primes.size();

    while(1)
    {
        int n;
        cin>>n;
        if(!n)
            break;
        int mid=n/2;
        bool found=0;

        for(int i=0;i<sz and primes[i]<=mid;i++)
        {
            if(found)
                break;
            if( !arr[n-primes[i]] )
            {
                cout<<n<<" = "<<primes[i]<<" + "<<n-primes[i]<<endl;
                found=1;
            }
        }
    }
}
