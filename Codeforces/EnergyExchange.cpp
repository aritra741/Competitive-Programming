#include <bits/stdc++.h>
#define eps 1e-7
using namespace std;

double arr[10007];
int n,k;

bool valid( double x )
{
    double add= 0, subt= 0;

    for( int i=0; i<n; i++ )
    {
        if( arr[i]>x )
            subt+= arr[i]-x;
        else if( arr[i]<x )
            add+= x-arr[i];
    }

    subt= subt-subt*k/100.0;

    if( subt+eps>add )
        return 1;
    return 0;
}

int main()
{
    cin>>n>>k;

    for( int i=0; i<n; i++ )
        cin>> arr[i];

    double low= 0.0, high= 1000.0;
    double ans;

    for( int i=1; i<=100; i++ )
    {
        double mid= (low+high)/2;
        if( valid(mid) )
            low= mid, ans= mid;
        else
            high= mid;
    }

    cout.precision(10);
    cout<<fixed<< ans <<endl;
}
