#include<bits/stdc++.h>
#define mx1 300007
#define mx2 1000007
#define mx3 200007
#define k 550
#define ll long long
#define sf(x) scanf("%d", &x)
#define pf(x) printf("%d\n", x)
using namespace std;

int arr[mx1], cnt[mx2];
int ans[mx1];
int sum;

struct query
{
    int l,r,id;
}qq[mx3];

bool cmp(query &a, query &b){
  if (a.l/k != b.l/k) return a.l<b.l;
  return a.l/k%2?a.r>b.r:a.r<b.r;
}

void jog( int id )
{
    cnt[ arr[id] ]++;
    if( cnt[ arr[id] ]==1 )
        sum++;
}

void baad( int id )
{
    cnt[ arr[id] ]--;
    if( cnt[ arr[id] ]==0 )
        sum--;
}

int main()
{
    int n,q;
    sf(n);

    for( int i=1;i<=n;i++ )
        sf(arr[i]);

    sf(q);

    for( int i=1;i<=q;i++ )
        sf(qq[i].l),
        sf(qq[i].r),
        qq[i].id= i;

    sort( qq, qq+q, cmp );

    int l= 0, r= 0;

    for( int i=1;i<=q;i++ )
    {
        while(l<qq[i].l) baad(l++);
        while(r<qq[i].r) jog(++r);
        while(l>qq[i].l) jog(--l);
        while(r>qq[i].r) baad(r--);

        ans[ qq[i].id ]= sum;
    }

    for( int i=1;i<=q;i++ )
        pf(ans[i]);
}

