#include <bits/stdc++.h>
#define ll long long
#define mx 1000007
using namespace std;

bool arr[mx];
vector <ll> prime;

void sieve()
{
    arr[0]=arr[1]=1;
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

ll nod( ll n )
{
    int sz= prime.size();
    ll ans= 1, t= n;
    bool ins= 0;

    for(int i=0; i<sz and prime[i]<=n; i++)
    {
        int cnt= 0;
        while(n%prime[i]==0)
        {
            ins= 1;

            n/=prime[i];
            cnt++;
        }

        ans*=(cnt+1);
    }

    if(n>1)
    {
        int cnt= 0;

        while(t%n==0)
            t/=n, cnt++;
        ans*=(cnt+1);
    }

    return ans;
}

int main()
{
    sieve();

    ll n;
    cin>>n;

    cout<< nod(n) <<endl;

}
