#include<bits/stdc++.h>
using namespace std;

double arr[200007];

int main()
{
    int n,w;
    cin>>n>>w;

    for( int i=0;i<2*n;i++ )
        cin>>arr[i];

    sort( arr, arr+2*n );

    double gg= arr[0], bb= arr[n];
    double l= 0, r= gg;
    double ans;

    for( int i=0;i<100;i++ )
    {
        double mid= (l+r)/2;

        if(mid*2<=bb and mid*n+mid*2*n<=w )
            ans= mid, l= mid;
        else
            r= mid;
    }

    cout<<setprecision(10)<<fixed<< ans*n+ans*2*n <<endl;
}
