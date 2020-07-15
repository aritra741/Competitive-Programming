#include<bits/stdc++.h>
#define ll long long
using namespace std;


struct PT
{
    ll x, y;
    PT() {}
    PT(ll x, ll y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
};

vector<PT>ret(100007), p;

bool cmp( PT a, PT b )
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x>b.x;
}

ll area( PT p, PT q, PT r )
{
    ll x[]= {p.x, q.x, r.x};
    ll y[]= {p.y, q.y, r.y};

    ll a= 0;
    ll j= 2;

    for(ll i=0; i<3; i++)
    {
        a+=(x[j]+x[i])*(y[j]-y[i]);
        j= i;
    }

    return llabs(a);
}

ll sign( PT p, PT q, PT r )
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

void bord()
{
    ll k=0, n= p.size();
    sort(p.begin(),p.end(),cmp);

    for(ll i=0; i<n; i++)
    {
        while(k>=2 and sign(ret[k-2], ret[k-1], p[i])!=2)
            k--;
        ret[k++]= p[i];
    }

    ret.resize(k);
}

int main()
{
    int n;
    cin>>n;

    p.resize(n);

    for( int i=0;i<n;i++ )
        cin>>p[i].x>>p[i].y, p[i].y-= p[i].x*p[i].x;

    bord();

    int ans= ret.size()-1;

    if( ret.size()>1 and ret[0].x==ret[1].x )
        ans--;
    if( ret.size()>2 and ret[ ret.size()-1 ].x==ret[ ret.size()-2 ].x )
        ans--;

    cout<< ans <<endl;
}
