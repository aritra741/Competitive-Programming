#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll a,b,c,x,y;

ll exg( ll a, ll b, ll &x, ll &y )
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }

    ll r=exg(b,a%b,x,y);
    ll tmp=x;
    x=y;
    y=tmp-a/b*y;

    return r;
}

int main()
{
    cin>>a>>b>>c;
    c= -c;
    ll gcd= exg(a,b,x,y);

    if( c%gcd )
        cout<<"-1"<<endl;
    else
        cout<< x*c/gcd <<" "<< y*c/gcd <<endl;
}
