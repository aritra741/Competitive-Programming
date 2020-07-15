#include<bits/stdc++.h>
#define ll long long
#define mx 200007
#define inf 1e18
using namespace std;

ll arr[mx], brr[mx];
ll x,y;
int n,m;

ll ok( ll d )
{
    x= 0, y= 0;

    for( int i=0;i<n;i++ )
    {
        if( arr[i]<=d )
            x+= 2;
        else
            x+= 3;
    }

    for( int i=0;i<m;i++ )
    {
        if( brr[i]<=d )
            y+= 2;
        else
            y+= 3;
    }

    return x-y;
}

int main()
{
    cin>>n;

    ll mm= 0;

    for( int i=0;i<n;i++ )
        cin>> arr[i], mm= max( mm, arr[i] );

    cin>>m;

    for( int i=0;i<m;i++ )
        cin>> brr[i], mm= max( mm, arr[i] );

    ll l= 0, r= mm*2;
    ll p= 0, q= 0;
    ll ans= -inf;

    while(r-l>5)
    {
        ll mid= (l+r)/2;

        ll f1= ok(mid);
        ll x1= x, y1= y;
        ll f2= ok(mid+1);

        if( f2<f1 )
        {
            r= mid;

            if( f1>ans )
                ans= f1, p= x1, q= y1;
            else if( f1==ans and x1>p )
                p= x1, q= y1;
        }
        else
        {
            l= mid;

            if( f2>ans )
                ans= f2, p= x, q= y;
            else if( f2==ans and x>p )
                p= x, q= y;
        }
    }

    while(l<=r)
    {
        ll f= ok(l);

        if( f>ans )
            ans= f, p= x, q= y;
        else if( f==ans and x>p )
            p= x, q= y;

        l++;
    }

    cout<<p<<":"<<q<<endl;
}
