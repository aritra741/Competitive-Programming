#include<bits/stdc++.h>
#define ll long long
#define inf 10000000000000000LL
#define _max(x) (x? x->mx:(int)-1e9)
using namespace std;
random_device rd;
mt19937 rr(rd());

// 0 based implicit treap

typedef struct item * pitem;
struct item
{
    int prior, cnt;
    ll value, pref, suff, tot, best;

    item() {}

    item( int a, int b )
    {
        value = a;
        prior = b;
        pref = suff = best = tot = value;

        l = NULL;
        r = NULL;

        cnt= 0;
    }

    pitem l, r;
};

pitem root = NULL;

int cnt (pitem it)
{
    return it ? it->cnt : 0;
}

void combine( pitem t )
{
    // update data from t first, then l and r

    if(!t)
        return;

    t->tot = t->value;

    if ( t->l )
        t->tot += t->l->tot;
    if ( t->r )
        t->tot += t->r->tot;

    ll prefL = -inf, sumL = -inf, suffL = -inf;
    ll prefR = -inf, sumR = -inf, suffR = -inf;
    ll bestL = -inf, bestR= -inf;

    if ( t->l )
    {
        prefL = t->l->pref;
        suffL = t->l->suff;
        sumL = t->l->tot;
        bestL = t->l->best;
    }
    if ( t->r )
    {
        prefR = t->r->pref;
        suffR = t->r->suff;
        sumR = t->r->tot;
        bestR = t->r->best;
    }

    if(prefL!=-inf)
        t-> pref = max({ prefL, sumL + t->value, sumL, sumL + t->value + sumR, sumL+t->value+prefR });
    else
        t-> pref = max({ t->value, t->value + sumR, t->value+prefR });
    if(suffR!=-inf)
        t-> suff = max({ suffR, sumR + t->value, sumR, sumR + t->value + sumL, sumR+t->value+suffL });
    else
        t-> suff = max({ t->value, t->value + sumL, t->value+suffL });
        
    t->best = max({ bestR, bestL, t->pref, t->suff, t->tot, suffL + t->value, t->value + prefR, suffL + t->value + prefR, t->value, suffL, prefR, sumR, sumL });
}

void upd_cnt (pitem it)
{
    if (it)
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
    // if ( it )
    //     it->mx = max( it->value, max( _max(it->l), _max(it->r) ) );
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
    combine(t);
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
    combine(t);
}

void print_array (pitem t)
{
    if (!t)  return;

    print_array (t->l);
    printf ("%d ", t->value);
    print_array (t->r);
}

void insert_at_pos( int y, int pos )    // pass 0 based index
{
    pitem it = new item( y, rr() );
    pitem l, r, mid;
    split( root, l, mid, pos );
    merge( root, l, it );
    merge( root, root, mid );
}

void range_query( int x, int y ) // pass 0 based indices
{
    pitem l, r, mid;
    split( root, l, mid, x );
    split( mid, mid, r, y - x + 1 );

    // cout << mid->mx << "\n";

    merge( root, l, mid );
    merge( root, root, r );
}

void delete_pos( int pos ) // pass 0 based index
{
    pitem l, r, mid;

    split( root, l, mid, pos );
    split( mid, mid, r, 1 );
    free(mid);
    merge( root, l, r );
}

void replace_at_pos( int x, int pos ) // pass 0 based index
{
    delete_pos(pos);
    insert_at_pos( x, pos );
}

ll range_maxsum_query( int x, int y ) // pass 0 based index
{
    pitem l, r, mid;

    split( root, l, mid, x );
    split( mid, mid, r, y - x + 1 );

    ll ret = mid->best;

    merge( mid, mid, r );
    merge( root, l, mid );

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for ( int i = 0; i < n; i++ )
    {
        ll p;
        cin >> p;

        insert_at_pos( p, i );
    }

    int q;
    cin >> q;

    while (q--)
    {
        char c;

        cin >> c;

        if (c == 'I')
        {
            int x, y;
            cin >> x >> y;

            insert_at_pos( y, x-1 );
        }
        else if ( c == 'D' )
        {
            int x;
            cin >> x;

            delete_pos( x - 1 );
        }
        else if ( c == 'R' )
        {
            int x, y;
            cin >> x >> y;

            replace_at_pos(y, x - 1);
        }
        else
        {
            int x, y;
            cin >> x >> y;

            x--, y--;

            ll ans = range_maxsum_query(x, y);

            cout << ans << "\n";
        }

    }

    return 0;

}