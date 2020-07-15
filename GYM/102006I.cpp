#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct PT
{
    double x,y;
    PT(){}
    PT(double a, double b)
    {
        x= a, y= b;
    }
};

double dist( PT a, PT b )
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main()
{
    freopen( "robots.in", "r", stdin );
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,R,r;
        cin>>n>>R>>r;

        PT p[n+7];

        p[0]= PT( 0,0 );

        for( int i=1;i<=n;i++ )
            cin>>p[i].x>>p[i].y, p[i].x+= p[i-1].x, p[i].y+= p[i-1].y;

        PT cent(0,0);

        double P= 0.98, Q= 10000;

        for( ;Q>1e-9; )
        {
            int f= 0;
            double d= dist( cent, p[0] );

            for( int j=1;j<=n;j++ )
            {
                double now= dist( cent, p[j] );

                if(now>d)
                    d= now, f= j;
            }

            cent.x+= ( p[f].x-cent.x )*(Q/10000);
            cent.y+= ( p[f].y-cent.y )*(Q/10000);
            Q*= P;
        }

        cout<<setprecision(10)<<fixed<< -cent.x <<" "<<-cent.y<<"\n";
    }


}
