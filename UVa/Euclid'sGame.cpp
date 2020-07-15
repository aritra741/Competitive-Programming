#include <bits/stdc++.h>
#define ll long long
using namespace std;

int cnt;

void euclid( ll a, ll b )
{
    cnt++;
    if( b==0 )
        return;
    euclid( b, a%b );
}

int main()
{
    ll a,b;

    while(cin>>a>>b and a+b )
    {
        euclid( max(a,b), min(a,b) );

        if( cnt&1 )
            cout<<"Ollie wins\n";
        else
            cout<<"Stan wins\n";
        cnt= 0;
    }
}
