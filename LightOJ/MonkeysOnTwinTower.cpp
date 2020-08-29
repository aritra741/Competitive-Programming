#include <bits/stdc++.h>
#define inf INT_MAX
using namespace std;

int dp[1010][2];
int vis[1010][2];
int arr1[1010],arr2[1010];
int late1[1010],late2[1010];
int n,p;

int rec( int i, bool first )
{
    // cout<< i<<" "<<first<<endl;
    if(i>=n)
        return 0;
    if( vis[i][first]==p )
        return dp[i][first];
    int q1= inf,q2=inf,q3=inf;

    int val= (first)?arr1[i]:arr2[i];
    int lt=  (first)?late2[i+1]:late1[i+1];

    if( i<n-1 )
    {
        q1= val+rec( i+1,first );
        q2= val+lt+rec( i+1,!first );
    }

    if(i==n-1)
    {
        q1= val;
    }

    vis[i][first]= p;

    return dp[i][first]= min( q1,q2 );
}


int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        scanf("%d", &n);
        p++;

        for(int i=0; i<n; i++)
            scanf("%d",&arr1[i]);
        for(int i=0; i<n; i++)
            scanf("%d",&arr2[i]);
        for(int i=1; i<n; i++)
            scanf("%d",&late2[i]);
        for(int i=1; i<n; i++)
            scanf("%d",&late1[i]);

        int ans1= rec( 0,1 );
        p++;
        int ans2= rec( 0,0 );

        printf("Case %d: %d\n", t, min(ans1,ans2));
    }
}
