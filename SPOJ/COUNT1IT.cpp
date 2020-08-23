#include <bits/stdc++.h>
using namespace std;

struct item {
    int key, prior, cnt;
    item * l, * r;
    item() { }
    item (int key, int prior) : key(key), prior(prior), l(NULL), r(NULL), cnt(0) { }
};
typedef item * pitem;
pitem root= 0;

int cnt (pitem t) {
    return t ? t->cnt : 0;
}

void upd_cnt (pitem t) {
    if (t)
        t->cnt = 1 + cnt(t->l) + cnt (t->r);
}

int smallEqual( int x )
{
    pitem now= root;
    int ans= 0;

    while(now)
    {
        if( now->key<=x )
            ans++;
        if( now->key > x )
            now= now->l;
        else
            ans+= cnt(now->l), now= now->r;
    }

    return ans;
}

void split (pitem t, int key, pitem & l, pitem & r) {
    if (!t)
        l = r = NULL;
    else if (key < t->key)
        split (t->l, key, l, t->l),  r = t;
    else
        split (t->r, key, t->r, r),  l = t;
    upd_cnt(t);
}

void insert (pitem & t, pitem it) {
    if (!t)
        t = it;
    else if (it->prior > t->prior)
        split (t, it->key, it->l, it->r),  t = it;
    else
        insert (it->key < t->key ? t->l : t->r, it);

    upd_cnt(t);
}

void merge (pitem & t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt(t);
}

void erase (pitem & t, int key) {
    if (t->key == key)
        merge (t, t->l, t->r);
    else
        erase (key < t->key ? t->l : t->r, key);
}

pitem unite (pitem l, pitem r) {
    if (!l || !r)  return l ? l : r;
    if (l->prior < r->prior)  swap (l, r);
    pitem lt, rt;
    split (r, l->key, lt, rt);
    l->l = unite (l->l, lt);
    l->r = unite (l->r, rt);
    return l;
}

int Findkth( int k )
{
    if( k<1 or k>(root?cnt(root):0) )
        return -1;
    pitem cur= root;

    while(1)
    {
        if(cur->l)
        {
            if( k<=cnt(cur->l) )
                cur= cur->l;
            else if( cnt(cur->l)+1==k )
                return cur->key;
            else
            {
                k-= cnt(cur->l)+1;
                cur= cur->r;
            }
        }
        else
        {
            if(k==1)
                return cur->key;
            else
            {
                k--;
                cur= cur-> r;
            }
        }
    }
}

int main()
{
    int n,q;
    scanf("%d %d", &n, &q);

    for( int i=1;i<=n;i++ )
    {
        int x;
        scanf("%d", &x);

        pitem now= new item( x, rand() );
        insert( root, now );
    }

    while(q--)
    {
        int tp, x;
        scanf("%d %d", &tp, &x);

        if(tp==1)
        {
            int chhoto= smallEqual(x);
            pitem now= new item( x+chhoto, rand() );
            insert(root,now);
        }
        else if(tp==2)
        {
            int chhoto= smallEqual(x);
            printf("%d\n", chhoto);
        }
        else
        {
            int kth= Findkth(x);

            if(kth>-1)
                printf("%d\n", kth);
            else
                printf("invalid\n");
        }
    }
}
