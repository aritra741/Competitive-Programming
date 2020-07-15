#include<bits/stdc++.h>
#define mid ((b+e)/2)
#define SIZE 100007
using namespace std;

int arr[SIZE], tree[SIZE*40];
int left_node[SIZE*40], right_node[SIZE*40], st[SIZE*40], TOTAL = 0,n;
int root[SIZE];

int newleaf(int value)
{
    int p = ++TOTAL;
    left_node[p] = right_node[p] = 0; // null
    st[p] = value;
    return p;
}

int newparent(int lef, int rig)
{
    int p = ++TOTAL;
    left_node[p] = lef;
    right_node[p] = rig;
    st[p] = st[lef] + st[rig]; // immediately update value from children
    return p;
}


int build( int b, int e)
{
    if (b == e)
        return newleaf(arr[b]); // construct as leaf
    else
        return newparent(build(b, mid), build(mid+1, e)); // construct as parent
}

// Usage: int root = build(arr, 0, n - 1);


// return an int, a pointer to the new root of the tree
int update(int node, int b, int e,int i, int x )
{
    if (b == e)
        return newleaf(st[node] + x);
    if (i <= mid)
        return newparent(update(left_node[node], b, mid, i, x), right_node[node]);
    else
        return newparent(left_node[node], update(right_node[node], mid + 1, e, i, x));
}

// Usage:
// int new_version_root = update(i, x, root);
// Both roots are valid, you can query from both of them!

int sum_query(int node, int b, int e,int l, int r)
{
    if (e<l || b>r)
        return 0; // outside range
    if (b>=l && e<=r)
        return st[node]; // inside range
    return sum_query(left_node[node], b, mid, l, r) + sum_query(right_node[node], mid + 1, e, l, r);
}



// revert range [a:b] of p
int rangecopy(int node, int revert, int b, int e, int l, int r)
{
    if (b>r || e<l)
        return node; // keep version
    if (b>=l && e<=r)
        return revert; // reverted version
    return newparent(rangecopy(left_node[node], left_node[revert], b, mid,l,r), rangecopy(right_node[node], right_node[revert], mid+1, e,l,r));
}

// Usage: (revert a range [a:b] back to an old version)
// int reverted_root = rangecopy(a, b, root, old_version_root);

bool hasflag[SIZE]; // if node has a flag (sometimes, you can omit this)
int flag[SIZE];     // the actual value of the flag

// returns a new node with a lazy flag
int newlazykid(int node, int delta, int L, int R)
{
    int p = ++TOTAL;
    left_node[p] = left_node[node];
    right_node[p] = right_node[node];
    flag[p] = flag[node]; // need this since lazy kid might be lazy before
    hasflag[p] = true;

    /* range increase */
    flag[p] += delta;
    st[p] = st[node] + (R - L + 1) * delta;
    /* edit depending on the problem */

    return p;
}

void propagate(int node, int b, int e)
{
    if (hasflag[node])
    {
        if (b != e)   // spread the laziness
        {
            left_node[node] = newlazykid(left_node[node], flag[node], b, mid);
            right_node[node] = newlazykid(right_node[node], flag[node], mid + 1, e);
        }
        // reset flag
        hasflag[node] = false;
    }
}

// range update on [a:b] with value x, on the tree rooted at p

int range_update(int node, int b, int e, int l, int r, int x)
{
    if (b>r || e<l)
        return node;
    if (b>=l && e<=r)
        return newlazykid(node, x, b, e);
    propagate(node, b, e); // always do this before going down
    return newparent(range_update(left_node[node], b, mid, l, r, x), range_update(right_node[node], mid + 1, e, l, r, x));
}

// range query on [a:b], on the tree rooted at p

int range_query(int node, int b, int e, int l, int r)
{
    if (b>r || e<l)
        return 0;
    if (b>=l && e<=r)
        return st[node];
//    propagate(node, b, e); // always do this before going down
    return range_query(left_node[node], b, mid, l, r) + range_query(right_node[node], mid + 1, e, l, r);
}

int main()
{
    int n;
    scanf("%d", &n);

    for( int i=1; i<=n; i++)
        scanf("%d", &arr[i]);

    root[0]= build( 1, n );

    for( int i=1; i<=n; i++ )
        root[1]= update( root[0], 1, n, i, arr[i] );

    int q;
    scanf("%d", &q);

    int cnt= 2;

    while(q--)
    {
        int tp;

        scanf("%d", &tp);

        if(tp==1)
        {
            int idx, pos, v;
            scanf("%d %d %d", &idx, &pos, &v);

            //idx++;

            root[cnt++]= update( root[idx], 1, n, pos, v );
        }
        else
        {
            int idx, l, r;
            scanf("%d %d %d", &idx, &l, &r);

            int ans= range_query( root[idx+1], 1, n, l, r );

            printf("%d\n", ans);
        }
    }
}
