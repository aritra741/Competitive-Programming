#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[15][100][100][2];
ll vis[15][100][100][2];
string s,t,s1;
ll n,k,p;

ll Pow( ll x, ll y )
{
    ll ret= 1;

    while(y>0)
    {
        if( y&1 )
            ret=(ret*x)%k;
        x=(x*x)%k;
        y>>=1;
    }

    return ret%k;
}

ll rec( int i, ll modtot, ll moddig, ll small )
{
    if( i>=n )
    {
        if( !(modtot+moddig) )
            return 1;
        return 0;
    }

    if( vis[i][modtot][moddig][small]==p )
        return dp[i][modtot][moddig][small];

    int lim= (small)?9:s[i]-'0';
    ll ans= 0;

    for(int j=0; j<=lim; j++)
    {
        bool now= small;
        if( !small and j<(s[i]-'0') )
            now= 1;
        ans+= rec( i+1, ( modtot+(Pow(10,n-i-1)*j%k)%k )%k, (moddig+j)%k, now );
    }

    vis[i][modtot][moddig][small]= p;

    return dp[i][modtot][moddig][small]= ans;
}

int main()
{
    int tc;
    cin>>tc;

    for(int T=1; T<=tc; T++)
    {
        p++;
        cin>>s1>>t>>k;

        if(k>90)
        {
            cout<<"Case "<<T<<": 0"<<endl;
            continue;
        }

        s= t;
        n= s.size();
        ll b= rec( 0,0,0,0 )-1;

        ll tmp= stoll(s1);
        s= s1;
        p++;
        n= s.size();

        ll a= rec( 0,0,0,0 )-1;

        ll ans= b-a;
        ll mod= 0;

        for(int i=0; i<n; i++)
            mod= (mod+ (s[i]-'0') )%k;

        if( !(mod+ (tmp%k) ) )
            ans++;

        cout<<"Case "<<T<<": "<< ans <<endl;
    }
}
