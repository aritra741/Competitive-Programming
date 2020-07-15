#include <bits/stdc++.h>
#define ll long long
#define p1 31
#define p2 37
#define mod1 1000000021
#define mod2 1000003469
#define mx 1000007
#define pii pair<ll,ll>
#define f first
#define s second
using namespace std;

map<pii,ll> mp;
vector<int>adj[mx];
ll Pow1[mx], Pow2[mx];
pii pre[mx], post[mx];
ll inv1, inv2;

ll bigmod( ll x, ll y, ll m )
{
    ll res= 1;

    while(y>0)
    {
        if(y&1)
            res= (res*x)%m;
        x= (x*x)%m;
        y>>= 1;
    }

    return res;
}

void init()
{
    Pow1[0]= Pow2[0]= 1;

    for( int i=1; i<mx; i++ )
        Pow1[i]= (Pow1[i-1]*p1)%mod1,
                 Pow2[i]= (Pow2[i-1]*p2)%mod2;

    inv1= bigmod( p1, mod1-2, mod1 );
    inv2= bigmod( p2, mod2-2, mod2 );
}

int main()
{
    init();
    string s;
    cin>>s;

    int sz= s.size();
    int arr[sz], cnt= 0;

    for( int i=0; i<sz-1; i++ )
    {
        pre[i+1].f= ( pre[i].f+(s[i]*Pow1[i+1])%mod1 )%mod1;
        pre[i+1].s= ( pre[i].s+(s[i]*Pow2[i+1])%mod2 )%mod2;

        post[i+1].f= ( (post[i].f*p1)%mod1+(s[ sz-i-1 ]*p1)%mod1 )%mod1;
        post[i+1].s= ( (post[i].s*p2)%mod2+(s[ sz-i-1 ]*p2)%mod2 )%mod2;

        if( pre[i+1]==post[i+1] )
            arr[cnt++]= i+1;
    }

    int low= 0, high= cnt-1;

    while( high>low+5 )
    {
        int mid= (low+high)/2;
        int md= arr[mid];
        //cout<<low<<" "<<high<<endl;
        if( pre[md]!=post[md] )
        {
            high= mid;
            continue;
        }

        ll h1= 0, h2= 0;

        for( int i=1; i<=md; i++ )
            h1= ( h1+ (s[i]*Pow1[i])%mod1 )%mod1,
            h2= ( h2+ (s[i]*Pow2[i])%mod2 )%mod2;

        if( h1==pre[md].f and h2==pre[md].s )
        {
            low= mid;
            continue;
        }

        bool ff= 0;

        for( int i=md+1; i<sz-1; i++ )
        {
            h1= ( h1- (s[i-md]*p1)%mod1 + mod1 )%mod1;
            h1= (h1*inv1)%mod1;
            h1= ( h1+ (s[i]*Pow1[md])%mod1 )%mod1;

            h2= ( h2- (s[i-md]*p2)%mod2 + mod2 )%mod2;
            h2= (h2*inv2)%mod2;
            h2= ( h2+ (s[i]*Pow2[md])%mod2 )%mod2;

           // cout<<h1<<" "<<h2<<" "<<pre[md].f<<" "<<pre[md].s<<endl;
            if( h1==pre[md].f and h2==pre[md].s )
            {
                ff= 1;
                break;
            }
        }

        if(ff)
            low= mid;
        else
            high= mid;
    }

    int ans= -1;
    bool ff= 0;

    for( int j=low; j<=high; j++ )
    {
        ll h1= 0, h2= 0;
        int jj= arr[j];

        for( int i=1; i<=jj and i<sz-1; i++ )
            h1= ( h1+ (s[i]*Pow1[i])%mod1 )%mod1,
            h2= ( h2+ (s[i]*Pow2[i])%mod2 )%mod2;

        if( h1==pre[jj].f and h2==pre[jj].s )
                ff= 1, ans= max( ans, jj );

        for( int i=jj+1; i<sz-1; i++ )
        {
            h1= ( h1- (s[i-jj]*p1)%mod1 + mod1 )%mod1;
            h1= (h1*inv1)%mod1;
            h1= ( h1+ (s[i]*Pow1[jj])%mod1 )%mod1;

            h2= ( h2- (s[i-jj]*p2)%mod2 + mod2 )%mod2;
            h2= (h2*inv2)%mod2;
            h2= ( h2+ (s[i]*Pow2[jj])%mod2 )%mod2;

            if( h1==pre[jj].f and h2==pre[jj].s )
                ff= 1, ans= jj;
        }
    }

    if( ff )
        for( int i=0; i<ans; i++ )
            cout<<s[i];
    else
        cout<<"Just a legend\n";
}
