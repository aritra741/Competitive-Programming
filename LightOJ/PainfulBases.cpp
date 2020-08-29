#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[65539][21];
int vis[65539][21];
int n,p,k,base,done;
string s;

int Pow( ll x, ll y )
{
    ll ans= 1;

    while(y>0)
    {
        if(y&1)
            ans=(ans*x)%k;
        x= (x*x)%k;
        y>>=1;
    }

    return ans%k;
}

ll rec( int mask, int mod )
{
    if(mask==done)
    {
        if( mod )
            return 0;
        return 1;
    }

    if(vis[mask][mod]==p)
        return dp[mask][mod];

    ll ans= 0;
    int i= __builtin_popcount(mask);
    for(int j=0; j<n; j++)
    {
        if( mask&(1<<j) )
            continue;

        ans+= rec( mask|(1<<j), (((int)(s[j])*Pow(base,i) )%k+ mod)%k );
    }

    vis[mask][mod]= p;

    return dp[mask][mod]= ans;
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        p++;
        cin>>base>>k;
        cin>>s;

        for(int i=0;i<s.size();i++)
            {
                if( s[i]>='A' and s[i]<='F' )
                    s[i]=s[i]-'A'+10;
                else
                    s[i]= s[i]-'0';
            }

        n= s.size();
        done= (1<<n)-1;
        cout<<"Case "<<t<<": "<< rec( 0,0 ) <<endl;
    }
}
