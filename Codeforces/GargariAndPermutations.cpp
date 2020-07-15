#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

int dp[1010][1010];
bool vis[1010][1010];
int arr[1010][1010];

int rec( int i, int j, int m, int n )
{
   // cout<<m<<" "<<n<<endl;
    if(m<0 or n<0)
        return 0;

    if(vis[m][n])
        return dp[m][n];

    int q1= -inf, q2= -inf, q3= -inf;

    if( arr[i][m]==arr[j][n] )
        q1= 1+rec( i, j, m-1, n-1 );
    else
    {
        q2= rec( i, j, m-1, n );
        q3= rec( i, j, m, n-1 );
    }

    vis[m][n]= 1;

    return dp[m][n]= max( q1, max( q2,q3 ) );
}

int main()
{
    int n,k;
    cin>>n>>k;

    for(int i=0; i<k; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &arr[i][j]);

    int ans= inf;

    for(int i=0; i<k; i++)
    {
        for(int j=i+1; j<k; j++)
        {
            int temp= rec( i, j, n-1, n-1 );
            ans= min( ans, temp );

            memset(vis, 0, sizeof(vis));
        }
    }

    printf("%d\n", ans);
}
