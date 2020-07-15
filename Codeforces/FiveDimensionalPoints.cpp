#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct point
{
    ll a,b,c,d,e;
} p[1007];

ll dot( point x, point y )
{
    return x.a*y.a+x.b*y.b+x.c*y.c+x.d*y.d+x.e*y.e;
}

ll val( point x )
{
    return sqrt(dot(x,x));
}

double angle( point x, point y )
{
    return acos( dot(x,y)/(val(x)*val(y)) );
}

void New( point &x, point y )
{
    x.a= y.a-x.a;
    x.b= y.b-x.b;
    x.c= y.c-x.c;
    x.d= y.d-x.d;
    x.e= y.e-x.e;
}

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
        cin>>p[i].a
           >>p[i].b
           >>p[i].c
           >>p[i].d
           >>p[i].e;

    set<int> idx;

    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            for(int k=j+1; k<n; k++)
            {
                New( p[i], p[j] );
                double ang1= angle( p[i],p[j] );
                double ang2= angle( p[i],p[k] );
            }
}
