#include <bits/stdc++.h>
#define inf 500
using namespace std;

int dp[110][110];
bool vis[110][110];
string s, t;

int rec( int m, int n )
{
    if(m<0 or n<0)
        return max(m+1, n+1);
    if(vis[m][n])
        return dp[m][n];
    int q1, q2= inf, q3= inf;

    if(s[m]==t[n])
        q1= rec(m-1,n-1);
    else
    {
        q1= 1+rec(m-1,n);
        q2= 1+rec(m,n-1);
        q3= 1+rec(m-1,n-1);
    }

    vis[m][n]= 1;

    return dp[m][n]= min(q1,min(q2,q3));
}

int main()
{
    int tc;
    cin>>tc;
    getchar();

    while(tc--)
    {
        getline(cin,s);
        getline(cin,t);
        cout<< rec( s.size()-1, t.size()-1 ) <<endl;

        memset(vis,0,sizeof(vis));
    }
}
