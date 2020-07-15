#include<bits/stdc++.h>
using namespace std;

struct PT
{
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &p)  const
    {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p)  const
    {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (double c)     const
    {
        return PT(x*c,   y*c  );
    }
    PT operator / (double c)     const
    {
        return PT(x/c,   y/c  );
    }
};
double cross(PT p, PT q)
{
    return p.x*q.y-p.y*q.x;
}

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);

    PT arr[n+5];
    double sum[n+5];

    for( int i=1;i<=n;i++ )
        scanf("%lf %lf", &arr[i].x, &arr[i].y);

    sum[0]= 0;
    double tot= 0;

    for( int i=1;i<=n;i++ )
        sum[i]= sum[i-1]+fabs(cross( arr[i]-arr[1], arr[i%n+1]-arr[1] )), tot= sum[i];
    double ans= 0;

    while(m--)
    {
        int a,b;
        scanf("%d %d", &a, &b);

        if(a>b)
            swap(a,b);

        double ekdik= ( tot-sum[b-1]+sum[a-1]+fabs(cross( arr[a]-arr[1], arr[b]-arr[1] ) ) );
        double onnodik= tot-ekdik;

        ans= max( ans, min (ekdik, onnodik) );

//        cout<<ekdik<<" "<<onnodik<<endl;
    }

    printf("%.6f\n", fabs(ans)*0.5);
}
