#include <bits/stdc++.h>
#define MX 300007
using namespace std;

int tree[MX];
int f[MX], l[MX];

void build(int node, int i, int j  )
{
    if(i==j)
        return tree[node]= arr[i];

    int lChild= 2*node;
    int rChild= 2*node+1;
    int mid= (l+r)/2;

    build( lChild, i, mid );
    build( rChild, mid+1, j );

    tree[node]=
}

int main()
{
    int n,q;
    scanf("%d %d", &n, &q);

    for(int i=1;i<=n;i++)
        scanf("%d", &arr[i]);

    build(1, 1, n);

    while(q--)
    {
        int i,j;
        scanf("%d %d", &i, &j);
        st ans= query(1, 1, n, i, j);

        printf("%d\n", ans.freq);
    }
}
