#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll n;
    cin>>n;

    if( !(n&1) )
        cout<<n/2<<endl;

    else
    {
        for(int i=3; i<=sqrt(n); i++)
            if(n%i==0)
            {
                cout<<1+(n-i)/2<<endl;
                n= 0;
                break;
            }
        if(n)
            cout<<1<<endl;

    }
}
