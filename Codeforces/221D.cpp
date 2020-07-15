#include<bits/stdc++.h>
#define mx 100007
#define k 320
#define ll long long
#define sf(x) scanf("%d", &x)
#define pf(x) printf("%d\n", x)
using namespace std;

int arr[mx];
unordered_map<int,int>cnt;
int ans[mx];
int sum;

struct query
{
    int l,r,id;
}qq[mx];

bool cmp(query &a, query &b){
  if (a.l/k != b.l/k) return a.l<b.l;
  return a.l/k%2?a.r>b.r:a.r<b.r;
}

void jog( int id )
{
    if(!id)
        return;
    if( cnt[ arr[id] ]==arr[id] )
        sum--;
    cnt[ arr[id] ]++;
    if( cnt[ arr[id] ]==arr[id] )
        sum++;

}

void baad( int id )
{
    if(!id)
        return;
    if( cnt[ arr[id] ]==arr[id] )
        sum--;
    cnt[ arr[id] ]--;
    if( cnt[ arr[id] ]==arr[id] )
        sum++;
}

int main()
{
    int n,q;
    sf(n);
    sf(q);

    for( int i=1;i<=n;i++ )
        sf(arr[i]);

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

