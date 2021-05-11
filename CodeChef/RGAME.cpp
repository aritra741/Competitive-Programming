#include <bits/stdc++.h>
#define ll long long
#define mx 100007
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

ll two_power[mx];

int main()
{
    fast;

    two_power[0]= 1;

    for( int i=1;i<mx;i++ )
        two_power[i]= (2LL*two_power[i-1])%mod;

    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        n++;
        ll arr[n+5], suff[n+5];

        for( int i=1;i<=n;i++ )
            cin>>arr[i];

        suff[n]= arr[n];

        for( int i=n-1;i>1;i-- )
        {
            suff[i]= ( arr[i]*two_power[n-i] )%mod;
            suff[i]= ( suff[i]+suff[i+1] )%mod;
        }

        ll ans= 0;

        for( int i=1;i<n;i++ )
        {
            ll pw;
            if(i==1)
                pw= 1;
            else
                pw= two_power[i-2];
            ll ekhon= (arr[i]*pw)%mod;
            ekhon= ( ekhon*suff[i+1]*2 )%mod;

            // cout<<i<<" "<<ekhon<<endl;

            ans= (ans+ekhon)%mod;
        }

        cout<< ans <<"\n";
    }
}