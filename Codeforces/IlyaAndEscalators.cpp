#include <bits/stdc++.h>
using namespace std;

double p;
int n,t;

double dp[2007][2007];
bool vis[2007][2007];

double rec( int i, int Time )
{
    if( i>=n or Time>=t )
        return 0.0;

    if(vis[i][Time])
        return dp[i][Time];

    double q1= p*(1+rec( i+1, Time+1 ));
    double q2= (1.0-p)*rec( i, Time+1 );

    vis[i][Time]= 1;
    return dp[i][Time]= q1+q2;
}

int main()
{
    cin>>n>>p>>t;

    cout<<setprecision(10)<<fixed<< rec(0, 0) <<endl;
}
