#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int mx= 0;
    int g= 0;
    set<int>st;

    for( int i=0;i<n;i++ )
    {
        int p;
        cin>>p;

        mx= max( mx, p );
        g= __gcd( g,p );
    }

    int tot= mx/g;

    int cnt= tot-n;

    if( cnt&1 )
        cout<<"Alice\n";
    else
        cout<<"Bob\n";
}
