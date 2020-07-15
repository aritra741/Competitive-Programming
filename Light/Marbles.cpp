#include <bits/stdc++.h>
#define pii pair<int,int>
#define poss first
#define tot second
using namespace std;

int B,R;
double dp[510][510][2];
int vis[510][510][2];
int p;

inline void Scan_f(int &a)
{
    char c=0;
    while(c<33)
    c=getc(stdin);
    a=0;
    while(c>33)
    {
        a=a*10+c-'0';
        c=getc(stdin);
    }
}

double rec( int b, int r, bool my )
{
    if(!r)
        return 1.00;
    if( !b )
        return 0.00;

    if( vis[b][r][my]==p )
        return dp[b][r][my];

    double q1=0.00,q2=0.00;

    if(my)
    {
        if(b)
            q1= ((double)b/(r+b))*rec( b-1, r, !my );
        if(r)
            q2= ((double)r/(r+b))*rec( b, r-1, !my );
    }

    else if (b)
        q1= rec( b-1, r, !my );

    vis[b][r][my]= p;

    return dp[b][r][my]= q1+q2;
}
int main()
{
    int tc;
    Scan_f(tc);
    p++;

    for(int t=1; t<=tc; t++)
    {
        Scan_f(R);
        Scan_f(B);

        printf("Case %d: %0.8f\n" ,t,rec( B,R,1 ));
    }
}
