#include <bits/stdc++.h>
#define ll long long
#define mx 1007
#define eps 1e-7
#define inf 1e18;
using namespace std;

int mark= 0;

struct point
{
    ll x,y;
} p[mx];

double slope(point a, point b)
{
    double numer= b.y-a.y;
    double denom= b.x-a.x;

    return numer/denom;
}

int isonline( point a, point b, point c )
{
    if( (b.y-a.y)*(c.x-b.x)-(c.y-b.y)*(b.x-a.x)==0 )
        return 1;
    return 0;
}

bool checkifposs( int n, point a, point b )
{
    bool poss= 1;
    vector<point> rem;

    for(int i=0; i<n; i++)
        if( !isonline(a, b, p[i]) )
        {
            mark= i;
            rem.push_back( p[i] );
        }

    if(rem.size()==0)
        return 0;
    if(rem.size()==1)
        return 1;

    for(int i=2; i<rem.size(); i++)
        if( !isonline( rem[0], rem[1], rem[i] ) )
            poss= 0;

    if(!poss)
        return 0;

    double m1= slope(a,b);
    double m2= slope(rem[0],rem[1]);


    if( fabs(m1-m2)<=eps )
        return 1;
    return 0;
}

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>p[i].y;
        p[i].x= i+1;
    }

    if( checkifposs( n, p[0], p[1]) )
    {
        cout<<"Yes";
        return 0;
    }

    int temp= mark;

    if(checkifposs( n, p[0], p[mark] ) )
    {
        cout<<"Yes";
        return 0;
    }

    if( checkifposs( n, p[1], p[temp]  ) )
    {
        cout<<"Yes";
        return 0;
    }

    cout<<"No";
}


