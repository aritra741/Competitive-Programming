#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    int tot= n/2;

    if(k<tot)
        return cout<<"-1", 0;

    if( n==1 and k )
        return cout<<"-1", 0;

    if( n==1 and !k )
        return cout<<"1", 0;

    if(k==tot)
    {
        for( int i=1;i<=n;i++ )
            cout<<i<<" ";
        return 0;
    }

    int fir= k-(tot-1);

    cout<<fir<<" "<<2*fir<<" ";

    int x= 1000000000;
    for( int i=3;i<=n;i++ )
        cout<<x--<<" ";
    cout<<endl;
}
