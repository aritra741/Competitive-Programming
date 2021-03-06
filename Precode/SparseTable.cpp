///Range minimum query
/// 0-based indexing
#include <bits/stdc++.h>
#define MX 500
using namespace std;

const int range= log2(MX)+1;

int table[MX][range];
int arr[MX];

void build(int n)
{
    for(int i=0;i<n;i++)
        table[i][0]=arr[i];

    for(int j=1; (1<<j)<=n;j++)
        for(int i=0;(i+(1<<j)-1)<n;i++)
            table[i][j]= min( table[i][j-1], table[i+(1<<(j-1))][j-1] );
}

int query(int l, int r)
{
    int j= log2(l-r+1);

    return min( table[l][j], table[r-(1<<j)+1][j] );
}

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>arr[i];
    build(n);

    int q;
    cin>>q;

    while(q--)
    {
        int l,r ;
        cin>>l>>r;

        cout<< query(l,r) <<endl;
    }
}
