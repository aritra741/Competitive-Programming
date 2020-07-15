#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    string t;
    cin>>t;

    ll b= 0,s= 0,c= 0;

    for( int i=0;i<t.size();i++ )
    {
        if( t[i]=='B' )
            b++;
        if( t[i]=='S' )
            s++;
        if( t[i]=='C' )
            c++;
    }

    ll nb, ns, nc;
    cin>>nb>>ns>>nc;

    ll pb,ps,pc;
    cin>>pb>>ps>>pc;

    ll x;
    cin>>x;

    ll l= 0, r= 1e15;
    ll ans= -1;

    while(r-l>5)
    {
        ll mid= (l+r)/2;

        ll blaage= b*mid;
        ll slaage= s*mid;
        ll claage= c*mid;

        ll y= x;

        ll be= max( 0LL, blaage-nb);
        ll se= max( 0LL, slaage-ns);
        ll ce= max( 0LL, claage-nc);

        y-= be*pb;
        y-= se*ps;
        y-= ce*pc;

        if( y>=0 )
            ans= mid, l= mid;
        else
            r= mid;
    }

    while(l<=r)
    {
        ll blaage= b*l;
        ll slaage= s*l;
        ll claage= c*l;

        ll y= x;

        ll be= max( 0LL, blaage-nb);
        ll se= max( 0LL, slaage-ns);
        ll ce= max( 0LL, claage-nc);

        y-= be*pb;
        y-= se*ps;
        y-= ce*pc;

        if(y>=0 and l>ans )
            ans=l;
        l++;
    }

    cout<< ans <<endl;
}
