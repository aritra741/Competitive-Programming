#include<bits/stdc++.h>
using namespace std;

struct PT
{
    double x, y;

    PT() {}
    PT( double a, double b )
    {
        x= a;
        y= b;
    }
} arr[60];

int n;

struct Line
{
    double a,b,c;
};

double dist( PT a, PT b )
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

PT inter( Line a, Line b )
{
    double del= a.a*b.b-a.b*b.a;
    double delX= a.c*b.b-a.b*b.c;
    double delY= a.a*b.c-a.c*b.a;

    return PT( delX/del, delY/del );
}

PT circle_er_center( PT a, PT b, PT c )
{
    Line u,v;
    u.a= a.x-b.x;
    u.b= a.y-b.y;
    u.c= u.a*(a.x+b.x)/2+u.b*(a.y+b.y)/2;
    v.a= a.x-c.x;
    v.b= a.y-c.y;
    v.c= v.a*(a.x+c.x)/2+v.b*(a.y+c.y)/2;

    return inter(u,v);
}

pair<double,PT> dui_ta_point( PT a, PT b )
{
    PT center;
    center.x= ( a.x+b.x )/2;
    center.y= ( a.y+b.y )/2;

    vector<double> distances;

    for( int i=1; i<=n; i++ )
        distances.push_back( dist( center, arr[i] ) );

    sort( distances.begin(), distances.end() );

    return {distances[n-1-4], center};
}

pair<double,PT> tin_ta_point( PT a, PT b, PT c )
{
    PT center= circle_er_center( a,b,c );

    vector<double> distances;

    for( int i=1; i<=n; i++ )
        distances.push_back( dist( center, arr[i] ) );

    sort( distances.begin(), distances.end() );

    return {distances[n-1-4],center};
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        cin>>n;

        for( int i=1; i<=n; i++ )
            cin>>arr[i].x>>arr[i].y;

        PT cent;
        double ans= 1e300;

        for( int i=1; i<=n; i++ )
            for( int j=i+1; j<=n; j++ )
            {
                pair<double,PT> now= dui_ta_point( arr[i], arr[j] );

                if( now.first<ans )
                    ans= now.first, cent= now.second;
            }

        for( int i=1; i<=n; i++ )
            for( int j=i+1; j<=n; j++ )
                for( int k=j+1; k<=n; k++ )
                {
                    pair<double,PT> now= tin_ta_point( arr[i], arr[j], arr[k] );

                    if( now.first<ans )
                        ans= now.first, cent= now.second;
                }

        cout<<setprecision(10)<<fixed<<cent.x<<" "<<cent.y<<" "<<sqrt(ans)<<"\n";
    }
}
