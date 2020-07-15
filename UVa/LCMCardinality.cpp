#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define mx 5000007
using namespace std;

vector <int> prime;

bool arr[mx];

void sieve()
{
    arr[0]=arr[1]=1;

    prime.push_back( 2 );

    for(ll i=3;i<mx;i+=2)
    {
        if(!arr[i])
        {
            prime.push_back( i );

            for(ll j=i*i;j<mx;j+=2*i)
                arr[j]=1;
        }
    }
}

int main()
{
    sieve();
    int sz= prime.size();

    ll n;
    while(1)
    {
        cin>>n;

        if(!n)
            break;

        ll temp=n;
        ll MX= -1;
        ll nod=1;
        int cnt=0;

        for(int i=0;i<sz and prime[i]<=n;i++)
        {
            ll p=0;
            if(n%prime[i]==0){
            while(n%prime[i]==0)
            {
                n/=prime[i];
                p++;
            }

            }



        }

        cout<<temp<<" "<<nod<<endl;

    }

}
