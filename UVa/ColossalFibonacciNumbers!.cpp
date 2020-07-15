#include <bits/stdc++.h>
#define ll unsigned long long
#define MX 10009
using namespace std;

ll dp[MX+5], mod;
bool vis[MX+5];
ll fib(ll u)
{
    if(vis[u])
        return dp[u]%mod;
    vis[u]=1;
    return dp[u]= (fib(u-1)%mod + fib(u-2)%mod)%mod;
}

ll bigmod(ll n,ll p,ll m)
{
    if(p==0){
        return 1%m;
    }
    if(p==1){
        return n%m;
    }
    ll re=bigmod(n,p/2,m)%m;
    re=((re%m)*(re%m))%m;
    if(p&1){
        re=((re%m)*(n%m))%m;
    }
    return re%m;
}


int main()
{
    int t;
    cin>>t;

    while(t--){
        memset(vis, 0, sizeof(vis));
        dp[0]=0;
        dp[1]=1;
        vis[0]=1;
        vis[1]=1;

        ll a,b,n,r;
        cin>>a>>b>>n;
        mod=n;
        fib(MX-1);
        map<ll,ll>mp;
        //cout<<"ok\n";
        for(int i=1;i<MX;i++){
            mp[dp[i]%n]++;
            if(dp[i]==0){
                r=i;
                break;
            }
        }
        ll indx=bigmod(a,b,r);
        cout<<dp[indx]%n<<endl;
    }
}
