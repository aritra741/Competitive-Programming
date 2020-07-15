#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<cstring>
#define mx 2000007
#define mod 18446744073709551615ULL
#define p 31
#define ll unsigned long long
using namespace std;

ll pp[mx];
ll inv= 1190112520884487200ULL;
int n;
char s[mx], t[mx];

ll bigmod( ll x, ll y )
{
    ll res= 1;

    while(y>0)
    {
        if(y&1)
            res= (res*x);
        x= (x*x);
        y>>= 1;
    }

    return res;
}

void init()
{
    pp[0]= 1;

    for( int i=1; i<mx; i++ )
        pp[i]= (pp[i-1]*p);

   // inv= bigmod( p, mod-2 );
}

bool poss( int x )
{
    ll hh1= 0, hh2= 0;

    for( int i=0; i<x; i++ )
        hh1= ( hh1+(s[i]*pp[i+1]) );
    for( int i=n-x; i<n; i++ )
        hh2= ( hh2+(t[i]*pp[i-n+x+1]));

    if(hh1==hh2)
        return 1;
    cout<<x<<" "<<hh1<<" "<<hh2<<endl;
    int cnt= 0;
    for( int i=x; i<=n; i++ )
    {
        hh1= (hh1- (p*s[i-x])+mod );
        hh1= (hh1*inv);
        hh1= ( hh1+ (s[i]*pp[x]) );

        hh2= ( hh2-(pp[x]*t[n-1-cnt])+mod );
        hh2= (hh2+t[n-x-cnt-1]);
        hh2= (hh2*p);
        cnt++;

//       cout<<hh1<<" "<<hh2<<endl;

        cout<<x<<" "<<hh1<<" "<<hh2<<endl;
        if(hh1==hh2)
            return 1;
    }

    return 0;
}
int main()
{
    init();
    int tt= 1;

    while(scanf("%s", s)==1)
    {
        n= strlen(s);

        if(n==3 and !strcmp(s,"END"))
            break;

        for( int i=0; i<n; i++ )
            t[i]= s[n-i-1];
        t[n]= 0;

        int low= 1, high= n;
        int ans= 1;

       // poss(6);
        while(low<=high)
        {
            int mid= (low+high)/2;

            if(mid&1)
                mid++;

            if( poss(mid) )
                ans= max(ans,mid), low= mid+2;
            else
                high= mid-2;
        }

        low= 1, high= n;

        while(low<=high)
        {
            int mid= (low+high)/2;

            if(!(mid&1))
                mid++;

            if( poss(mid) )
                ans= max(ans,mid), low= mid+2;
            else
                high= mid-2;
        }

        printf("Case %d: %d\n", tt++, ans);
    }
}
