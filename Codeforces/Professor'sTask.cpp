#include <bits/stdc++.h>
#define eps 1e-7
#define ll long long
using namespace std;

struct point
{
    ll x,y;
} base;

vector<point> ret(200007), p;

int sign( point p, point q, point r )
{
    ll val= (q.y-p.y)*(r.x-q.x)-
            (q.x-p.x)*(r.y-q.y);

    val=-val;

    if(val<0)
        return 1;
    if(val>0)
        return 2;
    return 0;
}

ll dist( point a, point b )
{
    return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

bool cmp( point a, point b )
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

void bord()
{
    int k=0, n= p.size();
    sort(p.begin(),p.end(),cmp);

    for(int i=0; i<n; i++)
    {
        while(k>=2 and sign(ret[k-2], ret[k-1], p[i])!=2)
            k--;
        ret[k++]= p[i];
    }
    int t= k;
    for(int i=n-2; i>=0; i--)
    {
        while(k>t and sign( ret[k-2], ret[k-1], p[i] )!=2)
            k--;
        ret[k++]= p[i];
    }

    ret.resize(k-1);
}

bool inside( point a, int type )
{
    int n= ret.size();
    int low= 1, high= n-1;

    while(high-low>1)
    {
        int mid= (low+high)/2;
        if( sign( ret[0],ret[mid], a )==1 )
            high= mid;
        else
            low= mid;
    }

    int val1= sign( ret[0],ret[low],a );
    int val2= sign( ret[low],ret[high],a );
    int val3= sign( ret[high],ret[0],a );

    if(val1==1)
        val1= -1;
    if(val2==1)
        val2= -1;
    if(val3==1)
        val3= -1;

    if( (val1*val2<0 or val2*val3<0 or val3*val1<0) )
        return false;

    return true;
}

void add( point a, vector<point> hull )
{
    int idx= 0;
    int n= hull.size();
    ll pt= 1e18;

    for(int i=0; i<n; i++)
    {
        ll d= dist( a, hull[i] );
        if( d < pt )
            pt= d, idx= i;
    }

    int up= idx;
    cout<<"idx->"<<idx<<endl;
    cout<<"Ekhon "<< sign( a, hull[up], hull[ (up+1)%n ] ) <<endl;
    while( sign( a, hull[up], hull[ (up+1)%n ] )!=2 )
        up= (up+1)%n;
    cout<<"pore up "<<up<<endl;
    int low= idx;

    while( sign( a, hull[low], hull[ (n+low-1)%n ]  )!=1 )
        low= (n+low-1)%n;

    int curr= up;
    if(up==low)
        curr= 0, low= n-1, up=0;
    ret.resize(0);
    cout<<"pos "<<up<<" "<<low<<endl;
    ret.push_back(hull[up]);
    //curr= (curr+1)%n;
    while(curr!=low)
    {

        curr= (curr+1)%n;ret.push_back(hull[curr]);
        cout<<"curr "<<curr<<endl;
    }

    point b;
    b.x= a.x;
    b.y= a.y;
    ret.push_back(b);
    cout<<" "<<ret.size()<<endl;
}

int main()
{
    int q;
    bool first= 1;
    scanf("%d", &q);

    for(int i=0; i<q; i++)
    {
        ll t;
        point b;
        scanf("%lld %lld %lld", &t, &b.x, &b.y);

        if(t==1)
        {
            if(first)
                p.push_back(b);
            else if( !inside( b, 1 ) )
            {
                add( b, ret );
                cout<<"HULL:\n";

                for(int i=0;i<ret.size();i++)
                    cout<<ret[i].x<<" "<<ret[i].y<<endl;
                cout<<endl;
            }
        }

        else
        {
            if( first )
            {
                first= 0;
                base= p[0];
                bord();

                cout<<"HULL:\n";

                for(int i=0;i<ret.size();i++)
                    cout<<ret[i].x<<" "<<ret[i].y<<endl;
                cout<<endl;
            }

            if( inside( b, 2 ) )
                printf("YES\n");
            else
                printf("NO\n");
        }

    }
}
