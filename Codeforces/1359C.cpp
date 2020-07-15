#include<bits/stdc++.h>
#define eps 1e-9
#define ll long long
using namespace std;

ll h,c,t;

long double ok( ll x )
{
    ll cd= x/2;
    ll hd= x-cd;
    ll hh= hd*h;
    ll cc= cd*c;

    long double now= (hh+cc+0.0)/x;

    return fabs(t-now);
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        cin>>h>>c>>t;

        long double agey= fabs(((h+c)/2.0)-t);

        ll l= 0, r= 1e6, ans= 1e9;

        while( r-l>5 )
        {
            ll mid= (l+r)/2;

            long double f1= ok( mid*2+1 );
            long double f2= ok( (mid+1)*2+1 );

//            cout<<2*l+1<<" "<<2*r+1<<endl;
//            cout<<setprecision(0)<<fixed<<" "<<l<<" "<<f1<<" "<<2*(mid+1)+1<<" "<<f2<<endl;

            if( f2<f1 )
                l= mid;
            else
                r= mid, ans= mid;
        }

//        cout<<2*l+1<<" "<<r*2+1<<endl;

        while(l<=r)
        {
//            cout<<setprecision(30)<<fixed<<2*l+1<<" "<<ok(2*l+1)<<endl;
            if( ok(l*2+1)<ok(ans*2+1) )
                ans= l;
            l= l+1;
        }

        if( ok(2*ans+1)<agey )
            ans= ans*2+1;
        else
            ans= 2;

        cout<< ans <<'\n';
    }
}

