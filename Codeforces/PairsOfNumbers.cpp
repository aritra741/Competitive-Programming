#include <bits/stdc++.h>
using namespace std;

int ret( int a, int b, int cnt )
{
    if( a==1 and b==1 )
        return cnt;
    if( a<=0 or b<=0 )
        return INT_MAX;
    if( a==1 or b==1 )
        return cnt+( max( a,b )-min( a,b ) );

    if( a>b )
        return ret( b, a%b, cnt+a/b );
    return ret( b%a, a, cnt+b/a );
}

int main()
{
    int n;
    cin>>n;

    int ans= INT_MAX;

    for( int i=1;i<n;i++ )
        ans= min( ans, ret( n, i, 0 ) );
    if( n==1 )
        ans= 0;

    cout<< ans <<endl;
}
