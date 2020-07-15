#include <bits/stdc++.h>
#define MX 200007
using namespace std;

int arr[MX], freq[MX], tree[MX*4];
map <int, int >li, fi;
map <int, int> mp;

void build( int node, int i, int j )
{
    if(i==j)
    {
        tree[node]=freq[i];
        return;
    }

    int mid= (i+j)/2;
    int lChild= 2*node;
    int rChild= 2*node+1;

    build( lChild, i, mid );
    build( rChild, mid+1, j );

    tree[node]= max( tree[lChild], tree[rChild] );

}

int rmq( int node, int l, int r, int i, int j )
{
    if(l>j or r<i)
        return -100007;

    if( l>=i and r<=j )
        return tree[node];

    int mid= (l+r)/2;

    int p1= rmq( 2*node, l, mid, i, j );
    int p2= rmq( 2*node+1, mid+1, r, i, j );

    return max( p1, p2 );
}

int occur( int i, int j, int n )
{

    int left= arr[i];
    int right= arr[j];

    if(left==right)
        return j-i+1;
    else
    {
        int locc= li[left]-i+1;
        int rocc= j- fi[right]+1;

        int q= rmq(1, 1, n, li[ left ]+1, fi[right]-1 );


        return max( q, max(locc, rocc) );
    }


}

int main()
{
    int tc;
    cin>>tc;
    for(int t=1; t<=tc; t++)
    {
        printf("Case %d:\n", t);

        int n,num,q;

        scanf("%d %d %d", &n, &num, &q);

        map <int, int> mp;

        for(int i=1; i<=n; i++)
        {
            scanf("%d", &arr[i]);
            mp[arr[i]]++;

            if( mp[arr[i]]==1 )
                fi[arr[i]]=i;
            if( i>1 and arr[i]!=arr[i-1] )
                li[ arr[i-1] ]= i-1;
            else if(i==n)
                li[ arr[i] ]= i;
        }

        for(int i=1; i<=n; i++)
            freq[i]=mp[ arr[i] ];

        build(1, 1, n);


        while(q--)
        {
            int i,j;
            scanf("%d %d", &i, &j);

            printf("%d\n",  occur(i, j, n) );
        }


    }
}
