#include <bits/stdc++.h>
#define mx 1000007
#define ll long long
using namespace std;

bool arr[mx];

void sieve()
{
    for(ll i=2;i<mx;i++)
    {
        if( !arr[i] )
            for(ll j=i*i;j<mx;j+=i)
                arr[j]= 1;
    }
}

int main()
{
    sieve();
    ll n;
    cin>>n;

    for(ll i=4;i<n;i++)
    {
        if( arr[i] and arr[n-i] )
        {
            cout<<i<<" "<<n-i<<endl;
            break;
        }
    }
}
