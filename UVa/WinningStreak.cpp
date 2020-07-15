#include <bits/stdc++.h>
using namespace std;

double dp[510][510][510];
bool vis[510][510][510];
int N;
double l,w;

double rec( int cnt, int idx, int p )
{
    if( cnt>=N )
    {
        return (double)p;
    }

    if(vis[cnt][idx][p])
        return dp[cnt][idx][p];

    double q1= l*rec( cnt+1, 0, max(p,0) );
    double q2= w*rec( cnt+1, idx+1, max(p,idx+1) );

    vis[cnt][idx][p]= 1;
    return dp[cnt][idx][p]= q1+q2;
}

int main()
{
    while(cin>>N>>w)
    {
        if(N==0)
            break;

        l= 1.0-w;

        cout<<setprecision(6)<<fixed<< rec(0,0,0) <<endl;

        memset(vis,0,sizeof(vis));
    }
}
