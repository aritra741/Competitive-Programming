#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll P[66];

int main()
{
    ll n,k;
    cin>>n>>k;

    P[0]= 1;
    ll x= 1;
    for( ll i=1;i<66;i++ )
    {
        if(x>=1e18)
            break;
        x*= k;
        P[i]= x;
    }

    ll low= 1, high= 1e18;
    ll ans;

    while(low<=high)
    {
        ll mid= (low+high)/2;
        ll sum= mid;

        for( int i=1;;i++ )
        {
            sum+= mid/P[i];
            if(sum>=n or mid/P[i]==0 )
                break;
        }

        if(sum>=n)
            high= mid-1, ans= mid;
        else
            low= mid+1;
    }

    cout<< ans <<endl;
}
