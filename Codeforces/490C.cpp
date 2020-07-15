#include<bits/stdc++.h>
#define ll long long
#define mx 1000007
using namespace std;

ll bigmod( ll x, ll y, ll mod )
{
    ll res= 1%mod;

    while( y>0 )
    {
        if( y&1 )
            res= (res*x)%mod;
        x= (x*x)%mod;
        y>>= 1;
    }

    return res%mod;
}

ll arr[mx], brr[mx];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;

    ll a,b;
    cin>>a>>b;

    int j= 0;

    for( int i=(int)s.size()-1;i>=0;i-- )
        brr[i]= ( brr[i+1]+ (bigmod( 10LL, j++, b )*(s[i]-'0'))%b )%b;

    for( int i=0;i<s.size();i++ )
    {
        arr[i]= (s[i]-'0')%a;

        if(i)
            arr[i]= (( arr[i-1]*10 )%a+arr[i] )%a;

        if( !arr[i] and i+1<s.size() and s[i+1]!='0' and !brr[i+1] )
        {
            cout<<"YES\n";

            for( int k=0;k<=i;k++ )
                cout<<s[k];
            cout<<endl;
            for( int k=i+1;k<s.size();k++ )
                cout<<s[k];
            return 0;
        }
    }

    cout<<"NO\n";
}
