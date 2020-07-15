#include <bits/stdc++.h>
using namespace std;

string s,t;
int dp[1010][1010];
bool vis[1010][1010];

int rec( int m, int n )
{
    if(m<0 or n<0)
        return 0;
    if(vis[m][n])
        return dp[m][n];
    int q1=0,q2=0,q3=0;

    if(s[m]==t[n])
        q1= 1+rec(m-1,n-1);
    else
    {
        q1= rec(m-1,n-1);
        q2= rec(m,n-1);
        q3= rec(m-1,n);
    }

    vis[m][n]= 1;

    return dp[m][n]= max(q1,max(q2,q3));
}

int main()
{
    while(getline(cin,s))
    {
        getline(cin,t);

        cout<< rec(s.size()-1, t.size()-1) <<endl;

        memset(vis,0,sizeof(vis));
    }
}
