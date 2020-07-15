#include <bits/stdc++.h>
#define ll long long
#define mx 1000007
using namespace std;

bool arr[mx];
vector<ll> pr;

void sieve()
{
    arr[0]=arr[1]=1;
    pr.push_back(2);

    for(ll i=3; i<mx; i+=2)
    {
        if(!arr[i])
        {
            pr.push_back(i);
            for(ll j=i*i; j<mx; j+=i)
                arr[j]=1;
        }
    }
}

int main()
{
    sieve();

    ll n;
    cin>>n;

    ll cnt= 0;
    ll temp= n, fir= n;

    for(ll i=0; n!=1 and i<pr.size() and pr[i]*pr[i]<=n; i++)
    {
        if(i==0 and n%pr[i]==0 )
        {
            cnt+=n/pr[i];
            n=1;
        }

        else if(n%pr[i]==0)
        {
            cnt++;
            n-=pr[i];

        }

        if(n!=temp)
            i=-1, temp= n;
    }

    if(n==fir)
        cnt++;

    cout<<cnt<<endl;
}
