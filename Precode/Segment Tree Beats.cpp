#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node
{
    ll mx, mx2, cntmx, sum;
};

ll arr[1010101];
Node tree[4040404];

Node f(Node a, Node b)
{
    if(a.mx == b.mx)
        return {a.mx, max(a.mx2, b.mx2), a.cntmx + b.cntmx, a.sum + b.sum};
    if(a.mx > b.mx)
        swap(a, b);
    return {b.mx, max(a.mx, b.mx2), b.cntmx, a.sum + b.sum};
}

Node init(int node, int s, int e)
{
    if(s == e)
        return tree[node] = {arr[s], -1, 1, arr[s]};
    int m = s + e >> 1;
    return tree[node] = f(init(node*2, s, m), init(node*2+1, m+1, e));
}

void push(int node, int s, int e)
{
    if(s == e)
        return;
    for(auto i :
            {
                node*2, node*2+1
            })
    {
        if(tree[node].mx < tree[i].mx)
        {
            tree[i].sum -= tree[i].cntmx * (tree[i].mx - tree[node].mx);
            tree[i].mx = tree[node].mx;
        }
    }
}

void update(int node, int s, int e, int l, int r, ll v)
{
    push(node, s, e);
    if(r < s || e < l || tree[node].mx <= v)
        return;
    if(l <= s && e <= r && tree[node].mx2 < v)
    {
        tree[node].sum -= tree[node].cntmx * (tree[node].mx - v);
        tree[node].mx = v;
        push(node, s, e);
        return;
    }
    int m = s + e >> 1;
    update(node*2, s, m, l, r, v);
    update(node*2+1, m+1, e, l, r, v);
    tree[node] = f(tree[node*2], tree[node*2+1]);
}

ll getmax(int node, int s, int e, int l, int r)
{
    push(node, s, e);
    if(r < s || e < l)
        return 0;
    if(l <= s && e <= r)
        return tree[node].mx;
    int m = s + e >> 1;
    return max(getmax(node*2, s, m, l, r), getmax(node*2+1, m+1, e, l, r));
}

ll getsum(int node, int s, int e, int l, int r)
{
    push(node, s, e);
    if(r < s || e < l)
        return 0;
    if(l <= s && e <= r)
        return tree[node].sum;
    int m = s + e >> 1;
    return getsum(node*2, s, m, l, r) + getsum(node*2+1, m+1, e, l, r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    init(1,1, n);
    int q;
    cin >> q;
    while(q--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            ll a, b, c;
            cin >> a >> b >> c;
            update(1, 1, n, a, b, c);
        }
        else if(op == 2)
        {
            ll a, b;
            cin >> a >> b;
            cout << getmax(1, 1, n, a, b) << "\n";
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            cout << getsum(1, 1, n, a, b) << "\n";
        }
    }
}
