#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,p;
    cin>>n>>p;

    for( int i=1;i<=31;i++ )
        if( n-i*p>0 and __builtin_popcount(n-i*p)<=i and n-i*p>=i  )
            return cout<<i, 0;

    cout<<"-1";
}
