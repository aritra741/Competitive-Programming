#include<bits/stdc++.h>
#define _max(x) (x? x->mx:(int)-1e9)
using namespace std;
random_device rd;
mt19937 rr(rd());
typedef struct item * pitem;
struct item
{
    int prior, value, cnt, mx;

    item() {}

    item( int a, int b )
    {
        value = a;
        prior = b;
        l = NULL;
        r = NULL;
        mx = value;
    }

    pitem l, r;
};

pitem root = NULL;

int cnt (pitem it)
{
    return it ? it->cnt : 0;
}

void upd_cnt (pitem it)
{
    if (it)
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
    if ( it )
        it->mx = max( it->value, max( _max(it->l), _max(it->r) ) );
}

void merge (pitem & t, pitem l, pitem r)
{
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0)
{
    if (!t)
        return void( l = r = 0 );

    int cur_key = add + cnt(t->l);
    if (key <= cur_key)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd_cnt (t);
}

void output (pitem t)
{
    if (!t)  return;

    output (t->l);
    printf ("%d ", t->value);
    output (t->r);
}

void insert_at_pos( pitem it, int pos )
{
    pitem mid;
    split( root, root, mid, pos - 1 );
    merge( root, root, it );
    merge( root, root, mid );
}

void range_query( int x, int y )
{
    pitem l, r, mid;
    split( root, l, mid, x - 1 );
    split( mid, mid, r, y - x + 1 );

    cout << mid->mx << "\n";

    merge( root, l, mid );
    merge( root, root, r );
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int q;
    cin >> q;

    while (q--)
    {
        char c;
        int h, pos;

        cin >> c;
        cin >> h >> pos;

        if (c == 'A')
        {
            pitem it = new item( h, rr() );
            insert_at_pos( it, pos );
            output(root);
            cout<<endl;
        }
        else
        {
            range_query( h, pos );
        }

    }

    return 0;

}