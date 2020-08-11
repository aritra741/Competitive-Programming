#include<bits/stdc++.h>
#define ll long long
#define inf 10000000000000000LL
using namespace std;

ll x[70], y[70];

int main()
{
    ll x0,y0,ax,ay,bx,by;
    cin>>x0>>y0>>ax>>ay>>bx>>by;

    ll xs,ys,t;
    cin>>xs>>ys>>t;

    int lim= 0;

    x[0]= x0;
    y[0]= y0;

    for( int i=0;;i++ )
    {
        lim++;
        x[i+1]= ax*x[i]+bx,
        y[i+1]= ay*y[i]+by;

//        cout<<x[i+1]<<" "<<y[i+1]<<endl;

        if( x[i+1]>=inf or y[i+1]>=inf )
            break;
    }

//    cout<<x[3]<<" and "<<y[3]<<endl;

    ll ans= 0;

    for( int i=0;i<=lim;i++ )
    {
        ll dist= llabs( x[i]-xs )+llabs( y[i]-ys );
        ll agey= dist;

        if( dist<=t )
            ans= max( 1LL, ans );

//        cout<<i<<" agey "<<dist<<endl;

        for( int j=i-1;j>=0;j-- )
        {
            dist+= llabs(x[j]-x[j+1])+llabs( y[j]-y[j+1] );

//            cout<<" "<<i<<" "<<j<<" "<<dist<<" "<<t<<endl;

            if( dist<=t )
                ans= max( ans, llabs(j-i)+1LL );
            else
                break;
        }

        dist= agey;

        for( int j=i+1;j<=lim;j++ )
        {
            dist+= llabs(x[j]-x[j-1])+llabs( y[j]-y[j-1] );

//            cout<<" "<<i<<" "<<j<<" "<<dist<<" "<<t<<endl;

            if( dist<=t )
                ans= max( ans, llabs(j-i)+1LL );
            else
                break;
        }
    }

    cout<< ans <<endl;
}

