///For future reference
#include <bits/stdc++.h>
#define ll long long
#define eps 1e-7
using namespace std;

struct point
{
    ll x,y;
};

ll sign( point p, point q, point r )
{
    ll val= (q.y-p.y)*(r.x-q.x)-
             (q.x-p.x)*(r.y-q.y);

    val=-val;                   ///In order to harmonize with the convention

    if(val<0)                   ///Clockwise
        return 1;
    else if(val>0)              ///Counter clockwise
        return 2;
    return 0;                   ///Co-linear
}

double dist( point a, point b )
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
    ll n;
    cin>>n;

    point a[n];

    for(ll i=0; i<n; i++)
        cin>>a[i].x>>a[i].y;

    ll m;
    cin>>m;

    bool inside= 1;

    while(m--)
    {
        point b;
        cin>>b.x>>b.y;
        ll low= 1, high= n-1;

        while(low<high-1)
        {
            ll mid= (low+high)/2;

            if( sign( a[0], a[mid], b )==2 )
                high= mid;
            else
                low= mid;
        }

        ll val1= sign( a[0], a[low], b );
        ll val2= sign( a[low], a[high], b );
        ll val3= sign( a[high], a[0], b );

        if(val1!=2 and val2!=2 and val3!=2);
        else inside= 0;

        if(val1==0)
        {
            if( fabs(dist(a[0],b)+dist(b,a[low])-dist(a[0],a[low]))>eps )
                inside= 0;
            else if( low==1 )
                inside= 0;
        }
        if(val2==0)
            inside= 0;
        if(val3==0)
            {
                if( fabs(dist(a[0],b)+dist(b,a[high])-dist(a[0],a[high]))>eps )
                    inside= 0;
                else if( high==n-1 )
                    inside= 0;
            }
    }

    if(inside)
        cout<<"YES";
    else
        cout<<"NO";
}

