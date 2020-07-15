#include <bits/stdc++.h>
#define ll long long
#define mx 100007
using namespace std;

struct point
{
    ll x,y;
} p[mx];

double dist( point a, point b )
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool inside( point c, point a, ll R, ll D, ll r )
{
    double d= dist( c,a );                  ///Had ll instead of double

    if(d-r>=R-D and d+r<=R)
        return 1;
    return 0;
}

int main()
{
    point center;
    center.x=0;
    center.y=0;

    ll R,D;
    cin>>R>>D;

    int n, cnt=0;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        ll r;
        cin>>p[i].x>>p[i].y>>r;

        if( inside(center, p[i], R, D, r) )
            cnt++;
    }

    cout<<cnt<<endl;
}
