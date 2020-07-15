#include <bits/stdc++.h>
#define ll long long
#define MX 70000
#define MAX(x,y,z,t,s) max(x, max(y, max(z, max(s,t) ) ) )
#define MAXX(x, y, z) max(x, max(y,z) )
using namespace std;

int arr[MX];

struct st{
    ll pre_sum, suf_sum, max_sum, tot;
}tree[4*MX];

void build( int node, int l, int r)
{
    if(l==r)
    {
        tree[node].pre_sum=tree[node].suf_sum=tree[node].max_sum=tree[node].tot=arr[l];
        return;
    }

    int lChild= 2*node;
    int rChild= 2*node+1;
    int mid= (l+r)/2;

    build(lChild, l, mid);
    build(rChild, mid+1, r);

    tree[node].pre_sum= max( tree[lChild].pre_sum, tree[lChild].tot+tree[rChild].pre_sum );
    tree[node].suf_sum= max( tree[rChild].suf_sum, tree[rChild].tot+tree[lChild].suf_sum );
    tree[node].tot= tree[lChild].tot+tree[rChild].tot;

    ll other= max( tree[lChild].max_sum, tree[rChild].max_sum );

    tree[node].max_sum= MAXX(tree[node].tot, tree[lChild].suf_sum+tree[rChild].pre_sum, other);

}

st query( int node, int l, int r, int i, int j )
{
    if(l>j or r<i)
        {
            st nll;
            nll.pre_sum=nll.suf_sum=nll.max_sum=nll.tot=-100000000;

            return nll;
        }

    if(l>=i and r<=j)
        return tree[node];

    int lChild= 2*node;
    int rChild= 2*node+1;
    int mid= (l+r)/2;

    st q1= query( lChild, l, mid, i, j );
    st q2= query( rChild, mid+1, r, i, j );

    st ret;

    ret.pre_sum= max( q1.pre_sum, q1.tot+q2.pre_sum );
    ret.suf_sum= max( q2.suf_sum, q2.tot+q1.suf_sum );
    ret.tot= q1.tot+q2.tot;

    ret.max_sum= MAXX(ret.tot, q1.suf_sum+q2.pre_sum, max(q1.max_sum, q2.max_sum));

    return ret;
}

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        scanf("%d",&arr[i]);

    build( 1, 1, n );

    int q;
    cin>>q;

    while(q--)
    {
        int i,j;
        scanf("%d %d", &i, &j);

        st ans=query( 1, 1, n, i, j );

        cout<< ans.max_sum <<endl;
    }
}
