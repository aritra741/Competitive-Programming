#include <bits/stdc++.h>
#define inf INT_MAX
using namespace std;

int tab[55][55];
bool vis[55][55];
int arr[55];
int n,l;

int rec( int l, int r )
{
    if(r==l+1)
        return 0;
    if(vis[l][r])
        return tab[l][r];

    int ans= inf;

    for(int i=l+1; i<r; i++)
    {
        int q1= rec( l, i );
        int q2= rec( i, r );

        ans= min( ans, q1+q2+arr[r]-arr[l] );
    }

    vis[l][r]= 1;

    return tab[l][r]= ans;

}

int main()
{
    while(1)
    {
        cin>>l;

        if(!l)
            break;

        cin>>n;

        for(int i=1; i<=n; i++)
            cin>>arr[i];
        arr[n+1]= l;

        cout<<"The minimum cutting is "<< rec( 0, n+1 ) <<"."<<endl;

        memset( vis, 0, sizeof(vis) );
    }
}
