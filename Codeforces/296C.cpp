#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define ff first
#define ss second
#define mx 100007
using namespace std;

ll arr[mx], val[mx], freq[mx], freq2[mx];
pii q[mx];

int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    for( int i=1;i<=n;i++ )
        cin>> arr[i];

    for( int i=1;i<=m;i++ )
        cin>> q[i].ff >> q[i].ss>> val[i];

    int l,r;
    for( int i=1;i<=k;i++ )
        cin>>l>>r, freq[l]++, freq[r+1]--;

    for( int i=1;i<=m;i++ )
        freq[i]+= freq[i-1];

    for( int i=1;i<=m;i++ )
        freq2[ q[i].ff ]+= val[i]*freq[i], freq2[ q[i].ss+1 ]-= val[i]*freq[i];

    for( int i=1;i<=n;i++ )
        freq2[i]+= freq2[i-1];

    for( int i=1;i<=n;i++ )
        cout<< arr[i]+freq2[i] <<" ";
}
