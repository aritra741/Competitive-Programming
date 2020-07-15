#include <bits/stdc++.h>
#define inf 1e7
using namespace std;

int dp[1010][1010];
bool vis[1010][1010];

string s, t;

int rec(int l, int r)
{
    if(l<0 or r<0)
        return max(l+1,r+1);
    if(vis[l][r])
        return dp[l][r];

    int q1=inf,q2=inf,q3=inf,q4=inf;

    if(s[l]==t[r])
        q1= rec(l-1,r-1);

    else
    {
        q1= 1+rec(l,r-1);
        q2= 1+rec(l-1,r);
        q3= 1+rec(l-1,r-1);

        if(l>0 and r>0 and s[l]==t[r-1])
        {
            int chng= 1, idx= l-1;
            while(idx>=0)
            {
                if( s[idx--]==t[r] )
                    break;
                chng++;
            }

            q4= chng+rec( idx, r-2 );       ///swap and delete the rest
        }
    }

    vis[l][r]= 1;

    return dp[l][r]= min( q1, min( q2, min( q3,q4 ) ) );
}

int main()
{
    while(1)
    {
        cin>>s>>t;

        if( s=="*" and s==t )
            break;

        cout<< rec( s.size()-1, t.size()-1 ) <<endl;

        memset(vis,0,sizeof(vis));
    }
}
