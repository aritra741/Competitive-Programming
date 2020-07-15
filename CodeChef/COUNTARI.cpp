#include<bits/stdc++.h>
#define ll long long
using namespace std;

namespace ntt
{
struct num
{
    double x,y;
    num()
    {
        x=y=0;
    }
    num(double x,double y):x(x),y(y) {}
};
inline num operator+(num a,num b)
{
    return num(a.x+b.x,a.y+b.y);
}
inline num operator-(num a,num b)
{
    return num(a.x-b.x,a.y-b.y);
}
inline num operator*(num a,num b)
{
    return num(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
}
inline num conj(num a)
{
    return num(a.x,-a.y);
}
int base=1;
vector<num> roots= {{0,0},{1,0}};
vector<int> rev= {0,1};
const double PI=acosl(-1.0);
void ensure_base(int nbase)
{
    if(nbase<=base)
        return;
    rev.resize(1<<nbase);
    for(int i=0; i<(1<<nbase); i++)
        rev[i]=(rev[i>>1]>>1)+((i&1)<<(nbase-1));
    roots.resize(1<<nbase);
    while(base<nbase)
    {
        double angle=2*PI/(1<<(base+1));
        for(int i=1<<(base-1); i<(1<<base); i++)
        {
            roots[i<<1]=roots[i];
            double angle_i=angle*(2*i+1-(1<<base));
            roots[(i<<1)+1]=num(cos(angle_i),sin(angle_i));
        }
        base++;
    }
}
void fft(vector<num> &a,int n=-1)
{
    if(n==-1)
        n=a.size();
    assert((n&(n-1))==0);
    int zeros=__builtin_ctz(n);
    ensure_base(zeros);
    int shift=base-zeros;
    for(int i=0; i<n; i++)
        if(i<(rev[i]>>shift))
            swap(a[i],a[rev[i]>>shift]);
    for(int k=1; k<n; k<<=1)
    {
        for(int i=0; i<n; i+=2*k)
        {
            for(int j=0; j<k; j++)
            {
                num z=a[i+j+k]*roots[j+k];
                a[i+j+k]=a[i+j]-z;
                a[i+j]=a[i+j]+z;
            }
        }
    }
}
vector<num> fa,fb;
vector<ll> multiply(vector<ll> &a, vector<ll> &b)
{
    ll need=a.size()+b.size()-1;
    ll nbase=0;
    while((1<<nbase)<need)
        nbase++;
    ensure_base(nbase);
    ll sz=1<<nbase;
    if(sz>(ll)fa.size())
        fa.resize(sz);
    for(ll i=0; i<sz; i++)
    {
        ll x=(i<(ll)a.size()?a[i]:0);
        ll y=(i<(ll)b.size()?b[i]:0);
        fa[i]=num(x,y);
    }
    fft(fa,sz);
    num r(0,-0.25/sz);
    for(ll i=0; i<=(sz>>1); i++)
    {
        ll j=(sz-i)&(sz-1);
        num z=(fa[j]*fa[j]-conj(fa[i]*fa[i]))*r;
        if(i!=j)
            fa[j]=(fa[i]*fa[i]-conj(fa[j]*fa[j]))*r;
        fa[i]=z;
    }
    fft(fa,sz);
    vector<ll> res(need);
    for(ll i=0; i<need; i++)
        res[i]=fa[i].x+0.5;
    return res;
}
vector<int> multiply(vector<int> &a,vector<int> &b,int m,int eq=0)
{
    int need=a.size()+b.size()-1;
    int nbase=0;
    while((1<<nbase)<need)
        nbase++;
    ensure_base(nbase);
    int sz=1<<nbase;
    if(sz>(int)fa.size())
        fa.resize(sz);
    for(int i=0; i<(int)a.size(); i++)
    {
        int x=(a[i]%m+m)%m;
        fa[i]=num(x&((1<<15)-1),x>>15);
    }
    fill(fa.begin()+a.size(),fa.begin()+sz,num{0,0});
    fft(fa,sz);
    if(sz>(int)fb.size())
        fb.resize(sz);
    if(eq)
        copy(fa.begin(),fa.begin()+sz,fb.begin());
    else
    {
        for(int i=0; i<(int)b.size(); i++)
        {
            int x=(b[i]%m+m)%m;
            fb[i]=num(x&((1<<15)-1),x>>15);
        }
        fill(fb.begin()+b.size(),fb.begin()+sz,num{0,0});
        fft(fb,sz);
    }
    double ratio=0.25/sz;
    num r2(0,-1),r3(ratio,0),r4(0,-ratio),r5(0,1);
    for(int i=0; i<=(sz>>1); i++)
    {
        int j=(sz-i)&(sz-1);
        num a1=(fa[i]+conj(fa[j]));
        num a2=(fa[i]-conj(fa[j]))*r2;
        num b1=(fb[i]+conj(fb[j]))*r3;
        num b2=(fb[i]-conj(fb[j]))*r4;
        if(i!=j)
        {
            num c1=(fa[j]+conj(fa[i]));
            num c2=(fa[j]-conj(fa[i]))*r2;
            num d1=(fb[j]+conj(fb[i]))*r3;
            num d2=(fb[j]-conj(fb[i]))*r4;
            fa[i]=c1*d1+c2*d2*r5;
            fb[i]=c1*d2+c2*d1;
        }
        fa[j]=a1*b1+a2*b2*r5;
        fb[j]=a1*b2+a2*b1;
    }
    fft(fa,sz);
    fft(fb,sz);
    vector<int> res(need);
    for(int i=0; i<need; i++)
    {
        ll aa=fa[i].x+0.5;
        ll bb=fb[i].x+0.5;
        ll cc=fa[i].y+0.5;
        res[i]=(aa+((bb%m)<<15)+((cc%m)<<30))%m;
    }
    return res;
}
vector<int> square(vector<int> &a,int m)
{
    return multiply(a,a,m,1);
}
};

using namespace ntt;

int suff[30007], pre[30007], now[30007];

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n+5];

    for( int i=1;i<=n;i++ )
        scanf("%d", &arr[i]), suff[ arr[i] ]++ ;

    int b= sqrt( n )+.5;

    ll ans= 0;

    int shuru= 0, shesh= 0;

    for( ;shesh<n; )
    {
        int l= shesh+1;
        int r= min( n, l+b-1 );
        shesh= r;

        for( int i=l;i<=r;i++ )
            suff[ arr[i] ]--;

        for( int i=l;i<=r;i++ )
        {
            for( int j=i+1;j<=r;j++ )
            {
                if( 2*arr[i]-arr[j]>=0 and 2*arr[i]-arr[j]<=30000 )
                    ans+= pre[ 2*arr[i]-arr[j] ];  /// first element is before this block
                if( 2*arr[j]-arr[i]>=0 and 2*arr[j]-arr[i]<=30000 )
                    ans+= suff[ 2*arr[j]-arr[i] ]; /// last element is after this block
                if( 2*arr[i]-arr[j]>=0 and 2*arr[i]-arr[j]<=30000 )
                    ans+= now[ 2*arr[i]-arr[j] ];  /// each one is from this block
            }

            now[ arr[i] ]++;
        }

        vector<ll>a,b;

        for( int i=0;i<=30000;i++ )
            a.push_back( pre[i] ),
            b.push_back( suff[i] );

        vector<ll>v= multiply( a,b );

        for( int i=l;i<=r;i++ )
            ans+= v[ arr[i]*2 ];

        for( int i=l;i<=r;i++ )
            pre[ arr[i] ]++,  now[ arr[i] ]--;;
    }

    printf("%lld\n", ans);
}
