#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

int constructST(int arr[], int l, int r, int *st, int current)
{
    if(l==r)
    {
        st[current]=arr[l];
        return arr[l];
    }
    int mid=l+(r-l)/2;
    st[current]= min( constructST(arr, l, mid, st,current*2+1), constructST(arr, mid+1, r, st,current*2+2) );
    return st[current];
}

int *buildST(int arr[],int n)
{
    int x=(int)(ceil(log2(n)));
    int mx=2*(int)pow(2,x)-1;
    int *st=new int[mx];
    constructST(arr, 0, n-1, st, 0);
    return st;
}

int query(int *st, int l, int r, int ql, int qr, int current)
{
    if(l>qr || r<ql)
        return MAX;
    if(l>=ql && r<=qr)
        return st[current];
    int mid=l+(r-l)/2;
    return min( query(st, l, mid, ql, qr, current*2+1), query(st, mid+1, r, ql, qr, current*2+2) );
}

int main()
{

    int tc;

    scanf("%d", &tc);
    for(int i=1; i<=tc; i++)
    {
        getchar();
        int sz,q;
        scanf("%d %d", &sz, &q);
        int arr[sz];
        for(int j=0; j<sz; j++)
        {
            scanf("%d", &arr[j]);
        }
        printf("Case %d:\n", i);
        int *st=buildST(arr, sz);
        int ql,qr;
        for(int j=0; j<q; j++)
        {
            scanf("%d %d", &ql,&qr);
            int ans=query(st, 0, sz-1, ql-1, qr-1, 0);
            printf("%d\n", ans);
        }
    }
}
