#include <bits/stdc++.h>
#define mx 100007
#define ll long long
#define lchild 2*node
#define rchild 2*node+1
#define mid (l+r)/2
#define mod 1000000007
#define pii pair<int,int>
using namespace std;

ll tree[4*mx];
pii arr[mx];
map<int,int> mp;
int idx[mx];

ll query( int node, int l, int r, int i, int j )
{
    if( l>j or r<i )
        return 0LL;
    if( l>=i and r<=j )
        return tree[node];

    ll q1= query( lchild, l, mid, i, j );
    ll q2= query( rchild, mid+1, r, i, j );

    return (q1+q2)%mod;
}

void update( int node, int l, int r, int i, ll val )
{
    if( l>i or r<i )
        return;
    if( l>=i and r<=i )
    {
        tree[node]= (tree[node]+val)%mod;
        return;
    }

    update( lchild, l, mid, i, val );
    update( rchild, mid+1, r, i, val );

    tree[node]= (tree[lchild]+tree[rchild])%mod;
}

int main()
{
    int tc;
    cin>>tc;

    for( int t=1;t<=tc;t++ )
    {
        int n;
        scanf("%d", &n);

        for( int i=0;i<n;i++ )
        {
            scanf("%d", &arr[i].first);
            arr[i].second= i;
        }

        sort( arr, arr+n );
        int k= 1;

        for( int i=0;i<n;i++ )
        {
            if( mp.find(arr[i].first)==mp.end() )
                mp[arr[i].first]= k++;
            idx[arr[i].second]= mp[arr[i].first];
        }

        ll ans= 0;
        for( int i=0;i<n;i++ )
        {
            ll q= query( 1, 1, n, 0, idx[i]-1 );
            ans= (ans+q+1)%mod;
            update( 1, 1, n, idx[i], (q+1)%mod );
        }

        printf("Case %d: %lld\n", t, ans);
        mp.clear();
        memset( tree, 0, sizeof(tree) );
    }
}
