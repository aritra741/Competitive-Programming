#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1010][1010];
int hw[1010][2];

int rec( int i, bool ph )
{
    if( i>n )
        return 0;
    if( dp[i][ph]!=-1 )
        return dp[i][ph];

    int q1= 0,q2= 0;

    if( !i )
        q1= hw[i][0]+rec( i+1, 0 ),
        q2= hw[i][1]+rec( i+1, 1 );
    else
        q1= hw[i]
}
int main()
{
    cin>>n;
}
