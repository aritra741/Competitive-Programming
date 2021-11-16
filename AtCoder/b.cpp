#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;

bool vis[45][45];
bool dp[45][45];
string s,t;

bool isNum( char c )
{
    if( c>='0' and c<='9' )
        return 1;
    return 0;
}

bool isChar( char c )
{
    if( c>='a' and c<='z' )
        return 1;
    return 0;
}



bool rec( int i, int j )
{
    if( i==s.size() )
    {
        if( j==t.size() )
            return 1;
        return 0;
    }

    if( i>s.size() )
        return 0;
    if( j>t.size() )
        return 0;

    if( vis[i][j] )
        return dp[i][j];

    bool ret= 0;

    if( isChar(t[j]) and isChar(s[i]) )
    {
        if( s[i]!=t[j] )
            return 0;

        ret|= rec( i+1,j+1 );
    }
    
    if( isNum(t[j]) )
    {   
        int x= t[j]-'0';

        ret|= rec( i+x, j+1 );

        if( j+1<t.size() and isNum(t[j+1]) )
        {
            x*= 10;
            x+= t[j+1]-'0';

            ret|= rec( i+x, j+2 );
        }
    }

    if( isNum(s[i]) )
    {
        int x= s[i]-'0';

        ret|= rec( i+1, j+x );

        if( i+1<s.size() and isNum(s[i+1]) )
        {
            x*= 10;
            x+= s[i+1]-'0';

            ret|= rec( i+2, j+x );
        }
    }

    vis[i][j]= 1;

    return dp[i][j]= ret;
}

bool possiblyEquals(string s1, string s2) {
    
    s= s1;
    t= s2;

    return rec( 0, 0 );
}

int main()
{
}
