#include <bits/stdc++.h>
#define ll long long
#define mx 100007
#define inf 1000000000
using namespace std;

bool arr[mx];
vector<ll> prime;
vector<ll> ::iterator it;

void sieve()
{
    arr[0]=arr[1]= 1;
    prime.push_back(2);

    for(ll i=3;i<mx;i+=2)
    {
        if(!arr[i])
        {
            prime.push_back(i);
            for(ll j=i*i;j<mx;j+=i)
                arr[j]= 1;
        }
    }
}

int main()
{
    sieve();

    int n,m;
    cin>>n>>m;

    it= lower_bound( prime.begin(),prime.end(), n-1 );
    int pos= it-prime.begin();

    cout<< n-1 <<" "<< prime[pos] <<endl;

    for(int i=1;i<n-1;i++)
        cout<<i<<" "<<i+1<<" 1\n";

    cout<< n-1 <<" "<< n <<" "<< prime[pos]-(n-2) <<endl;

    int cnt= n;
    for(int i=1;i<=n and cnt<=m; i++)
        for(int j=i+2;j<=n and cnt<=m;j++)
            cout<<i<<" "<<j<<" "<<inf<<endl,
            cnt++;
}
