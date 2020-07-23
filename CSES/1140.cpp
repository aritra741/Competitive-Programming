#include<bits/stdc++.h>
#define mx 200007
#define pii pair<ll,ll>
#define ff first
#define ss second
#define ll long long
using namespace std;

struct din
{
    ll st, en, cost;

    din() {}

    din( int a, int b, ll c )
    {
        st= a;
        en= b;
        cost= c;
    }
};

set<pii>st;
int n;
din arr[mx];
ll dp[mx];

bool operator < ( din a, din b )
{
    return a.st<b.st;
}

ll rec( int i )
{
    if( i>=n )
        return 0;
    if( dp[i]!=-1 )
        return dp[i];

    ll ret= rec( i+1 );

    auto p= st.upper_bound( pii( arr[i].en, 1e9 ) );

    if( p!=st.end() )
        ret= max( ret, arr[i].cost+rec( p->ss ) );

    ret= max( ret, 1LL*arr[i].cost );

    return dp[i]= ret;
}

int main()
{
    memset( dp, -1, sizeof(dp) );

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    for( int i=0;i<n;i++ )
        cin>> arr[i].st >> arr[i].en >> arr[i].cost;

    sort( arr, arr+n );

    for( int i=0;i<n;i++ )
        st.insert( pii(arr[i].st, i) );

    cout<< rec( 0 ) <<endl;
}
