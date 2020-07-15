#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll Pow( ll x, ll y )
{
    ll ans= 1;

    while(y>0)
    {
        if(y&1)
            ans*=x;
        x*=x;
        y>>=1;
    }

    return ans;
}

int main()
{
    ll b,k;
    cin>>b>>k;

    ll arr[k];

    for(int i=0;i<k;i++)
        cin>>arr[i];

    ll ans= 0, t= k;

    for(int i=0;i<k;i++)
    {
        ans+= arr[i]*Pow( b,t-1 );
        t--;
    }

    if(ans&1)
        cout<<"odd";
    else
        cout<<"even";
}
