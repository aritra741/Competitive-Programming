#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr[210];
ll dp[210][25][15];
ll vis[210][25][15];
ll p,n,m,d;

ll rec( int i, ll mod, ll cnt )
{
    if(cnt==m)
    {
        if(mod)
            return 0;
        return 1;
    }

    if(i>=n)
    {
        if( cnt==m and !mod )
            return 1;
        return 0;
    }

    if( vis[i][mod][cnt]==p )
        return dp[i][mod][cnt];

    ll q1= rec( i+1, (mod+(arr[i]%d+d)%d)%d, cnt+1 );
    ll q2= rec( i+1, mod, cnt );

    vis[i][mod][cnt]= p;

    return dp[i][mod][cnt]= q1+q2;
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        cout<<"Case "<<t<<":\n";
        int q;
        cin>>n>>q;

        for(int i=0;i<n;i++)
            cin>>arr[i];

        while(q--)
        {
            p++;
            cin>>d>>m;

            cout<< rec( 0, 0, 0 ) <<endl;
        }
    }
}
