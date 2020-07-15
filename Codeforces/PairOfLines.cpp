#include <bits/stdc++.h>
#define ll long long
#define mx 100007
using namespace std;

int mark= 0;

struct point
{
    ll x,y;
} p[mx];

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

    if( rem.size()<3 )
        return 1;

    for(int i=2; i<rem.size(); i++)
        if( !isonline( rem[0], rem[1], rem[i] ) )
            poss= 0;

    if(poss)
        return 1;
    return 0;
}

int main()
{
    int n;
    cin>>n;

    if(n<3)
    {
        cout<<"YES";
        return 0;
    }

    for(int i=0; i<n; i++)
        cin>>p[i].x>>p[i].y;

    if( checkifposs( n, p[0], p[1]) )
    {
        cout<<"YES";
        return 0;
    }

    int temp= mark;

    if(checkifposs( n, p[0], p[mark] ) )
    {
        cout<<"YES";
        return 0;
    }

    if( checkifposs( n, p[1], p[temp]  ) )
    {
        cout<<"YES";
        return 0;
    }

    cout<<"NO";
}

