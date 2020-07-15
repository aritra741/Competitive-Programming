#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll Log2( ll n )
{
    int cnt= 0;
    while(n>0)
        cnt++, n/=2;
    return cnt;
}

int main()
{
    ll n,k;
    cin>>n>>k;

    if(k==1)
        cout<<n<<endl;
    else
        cout<< (ll)((1LL<<(ll)(Log2(n)))-1LL) <<endl;
}
