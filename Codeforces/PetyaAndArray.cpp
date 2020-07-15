#include <bits/stdc++.h>
#define ll long long
#define L 2*node
#define R 2*node+1
#define MX 200007
using namespace std;

ll arr[MX], tree[MX*4];

void build( int node, int i, int j )
{
    if( i==j )
    {
        tree[node]=arr[i];
        return;
    }

    int mid= (i+j)/2;

    build( L, i, mid );
    build( L, mid+1, j );

    tree[node]= tree[L] + tree[R];

}

ll cnt=0;
int lvl=0;

void query( int node, int i, int j, int l, int r )
{
    if( i>r or j<l )
        return;

    if( i>=l and j<=r )


}

int main()
{

}
