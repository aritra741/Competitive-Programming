#include <bits/stdc++.h>
using namespace std;

int dp[52][52][52];
int vis[52][52][52];
int p;
string s,t,l;

int rec( int i, int j, int k )
{
    if( i<0 or j<0 or k<0 )
        return 0;
    if( vis[i][j][k]==p )
        return dp[i][j][k];

    int q1=0,q2=0,q3=0,q4=0,q5=0,q6=0,q7=0;
    int ans= 0;
    if( s[i]==t[j] and t[j]==l[k] )
        ans= 1+rec( i-1,j-1,k-1 );
    else
    {
        ans= rec( i-1, j, k );
        ans= max(ans,rec( i-1, j-1, k ));
        ans= max(ans,rec( i-1, j-1, k-1 ));
        ans= max(ans,rec( i, j-1, k-1 ));
        ans= max(ans,rec( i, j, k-1 ));
        ans= max(ans,rec( i-1, j, k-1 ));
        ans= max(ans,rec( i, j-1, k ));
    }

    vis[i][j][k]= p;

    return dp[i][j][k]= ans;
}

int main()
{
    int tc;
    cin>>tc;

    for(int T=1; T<=tc; T++)
    {
        p++;
        cin>>s>>t>>l;

        cout<<"Case "<<T<<": "<< rec( s.size()-1, t.size()-1, l.size()-1 ) <<endl;
    }
}
