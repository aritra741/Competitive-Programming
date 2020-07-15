#include <bits/stdc++.h>
#define ll long long
#define mx 300
using namespace std;

ll dp[305][1007];
bool vis[305][1007];
int target= 1001;

ll rec( int i, int tot )
{
    cout<<i<<" "<<tot<<endl;
    if(tot>target)
        return 0;
    if(tot==target)
        return 1;
    if(i>=mx)
        return 0;
    if(vis[i][tot])
        return dp[i][tot];

    ll q1= rec( i, tot+i+1 );
    ll q2= rec( i+1, tot );

    vis[i][tot]= 1;
    return dp[i][tot]= q1+q2;
}

int main()
{
    rec( 0, 0 );

    cout<< dp[0][0] <<endl;
}
