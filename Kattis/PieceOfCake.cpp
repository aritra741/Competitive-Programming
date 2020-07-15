#include<bits/stdc++.h>
using namespace std;

long double ncr[2507][2507];

struct PT
{
    long double x, y;
    PT() {}
    PT(long double x, long double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &p)  const
    {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p)  const
    {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (long double c)     const
    {
        return PT(x*c,   y*c  );
    }
    PT operator / (long double c)     const
    {
        return PT(x/c,   y/c  );
    }
};

long double cross(PT p, PT q)
{
    return p.x*q.y-p.y*q.x;
}

void init( int n )
{
    for( int i=0;i<=n;i++ )
        ncr[i][0]= 1;
    for( int i=0;i<=n;i++ )
        for( int j=1;j<=i;j++ )
            ncr[i][j]= ncr[i-1][j]+ncr[i-1][j-1];
}

int main()
{
    int n,k;
    cin>>n>>k;

    init(n);

    PT p[n+5];

    for( int i=1;i<=n;i++ )
        cin>>p[i].x>>p[i].y;

    long double res= 0.0;

    for( int i=1;i<=n;i++ )
    {
        for( int j= 1;j<=n;j++ )
        {
            if(i==j)
                continue;

            int baki;

            if( j>i )
                baki= j-i-1;
            else
                baki= n-(i-j+1);

            res+= cross( p[i], p[j] )*ncr[baki][k-2];
        }
    }

    res= fabs(res)*0.5;
    res/= ncr[n][k];

    cout<<setprecision(10)<<fixed<< res <<endl;
}
