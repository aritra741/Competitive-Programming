#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct point
{
    ll x,y;
};

int sign( point p, point q, point r )
{
    ll val= (q.y-p.y)*(r.x-q.x)-
            (q.x-p.x)*(r.y-q.y);

    val=-val;

    if(val<0)
        return 1;
    else if(val>0)
        return 2;
    return 0;
}


int main()
{
    point p,q,r;
    cin>>p.x>>p.y
    >>q.x>>q.y
    >>r.x>>r.y;

    int val= sign( p,q,r );

    if(!val)
        cout<<"TOWARDS\n";
    else if(val==1)
        cout<<"RIGHT\n";
    else
        cout<<"LEFT\n";
}
