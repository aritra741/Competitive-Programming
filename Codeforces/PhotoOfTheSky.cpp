#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[3000007];

int main()
{
    ll n;
    cin>>n;

    for(int i=0;i<2*n;i++)
        cin>>arr[i];

    sort(arr, arr+2*n);

    ll blx= arr[0];
    ll Try= arr[2*n-1];

    ll bly, Trx;
    ll ans= abs(Try- arr[n])*abs(blx- arr[n-1]);

    for(int i=1, j=1+n-1;j<2*n-1;i++)
    {
        bly= arr[i];
        Trx= arr[n+i-1];

        j=i+n-1;

        if(j>=2*n-1)
            break;

        ans= min( ans, abs(bly-Trx) * abs(Try-blx) );
    }

    cout<< ans <<endl;
}
