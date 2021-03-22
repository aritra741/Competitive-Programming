#include<bits/stdc++.h>
using namespace std;

#define inf 1001000009
#define infmx 1e18
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define MP make_pair
#define IOS ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define all(x) x.begin(),x.end()
///debug
#define wh(x)   cerr<<#x<<" is "<<x<<endl;
#define error(args...){string _s=#args;replace(_s.begin(),_s.end(),',',' ');stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it,args);}
void err(istream_iterator<string>it){cout<<endl;}
template<class H,class... T>void err(istream_iterator<string>it,H a,T... t){cerr<<*it<<" = "<<a<<" | ";err(++it,t...);}
template<class S,class T>ostream&operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;};
template<class T>auto&operator<<(ostream& os,vector<T>_v){bool a=1;for(auto x:_v){os<<(a?"":" ")<<x;a=0;}return os;}
///
inline void YN(bool f){cout<<(f?"YES":"NO")<<endl;}
inline void Yn(bool f){cout<<(f?"Yes":"No")<<endl;}
inline void yn(bool f){cout<<(f?"yes":"no")<<endl;}


typedef pair<ll,ll>pi;
typedef pair<long long,long long>pll;
typedef pair<pi,ll>ppi;
typedef pair<ll,pi>pip;
typedef vector<ll>vi;
typedef vector<pi>vpi;
const ll mod=1e9+7;
ll power(ll a,ll p){ll r=1,y=a;while(p){if(p&1)r=(1LL*r*y)%mod;p>>=1;y=(1LL*y*y)%mod;}return r;}

const ll N=2100000;
ll ara[N];
ll n;
bool possible(ll x)
{
    ll sum=0;
    for(ll i=1;i<=n;i++){
    	ll now= ara[i]-(-1);
        if(now<x)sum+=x-now;
    }

    // cout<<x<<" "<<sum<<endl;
    if(sum>=x)return false;
    return true;
}

int main()
{
    IOS;
    ll t;cin>>t;
    for(ll cs=1;cs<=t;cs++){
        cin>>n;

        ll mx= 0;

        for(ll i=1;i<=n;i++)cin>>ara[i], mx= max(mx, ara[i]);

        // if(!mx)
        // {
        // 	cout<<"Case #"<<cs<<": "<<"0"<<endl;
        // 	continue;
        // }

        ll l=0,r=10000000000000000, ans= 0;
        while(l<=r){
            ll mid=(l+r)/2;
            if(possible(mid))
                ans= mid, l=mid+1;
            else r=mid-1;
        }
        cout<<"Case #"<<cs<<": "<<ans<<endl;
    }
}