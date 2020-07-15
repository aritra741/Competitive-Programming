#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll a[2],b[2],c[2],d[2];

int main()
{
    int n;
    cin>>n;

    d[0]= 1;

    for( int i=1;i<=n;i++ )
    {
        int x= i%2;
        a[x]= ( b[x^1]+c[x^1]+d[x^1] )%mod;
        b[x]= ( a[x^1]+c[x^1]+d[x^1] )%mod;
        c[x]= ( b[x^1]+a[x^1]+d[x^1] )%mod;
        d[x]= ( b[x^1]+c[x^1]+a[x^1] )%mod;
    }

    cout<< d[n%2] <<endl;
}
