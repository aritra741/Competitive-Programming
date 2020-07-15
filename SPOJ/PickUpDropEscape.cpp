#include <bits/stdc++.h>
#define ll long long
using namespace std;

int arr[25];
int dp[25][25][25000];
int vis[25][25][25000];
int n,k, p= 1;

int rec( int i, int cnt, int Xor )
{
    if(cnt>=k)
        return Xor;
    if(i>=n)
        return 0;
    if(vis[i][cnt][Xor]==p)
        return dp[i][cnt][Xor];

    int q1= rec( i+1, cnt, Xor );
    int q2= rec( i+1, cnt+1, arr[i]^Xor );

    vis[i][cnt][Xor]= p;

    return dp[i][cnt][Xor]= max(q1,q2);
}


int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        scanf("%d %d", &n, &k);

        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);

        printf("%d\n",  rec( 0, 0, 0 ) );
        p++;
    }
}
