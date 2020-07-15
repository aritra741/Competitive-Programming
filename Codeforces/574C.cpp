#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll lcm( ll x, ll y )
{
    return (x/__gcd(x,y))*y;
}

ll arr[100007];
set<ll>st;

int main()
{
    int n;
    cin>>n;

    ll lm= 1;

    for( int i=0; i<n; i++ )
        cin>>arr[i];

    for( int i=0; i<n; i++ )
    {
        while(arr[i]%2==0)
            arr[i]/= 2;
        while(arr[i]%3==0)
            arr[i]/= 3;

        st.insert(arr[i]);

        if(st.size()>1)
            return cout<<"NO\n", 0;
    }

    cout<<"YES\n";
}
