#include<bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

pii dp[1007][1007];
int vis[1007][1007];
int labh[2][1007];
int n,m,p;
pii khali;

unordered_map<int,string>type1, type2;

pii rec( int i, int j )
{
    if( i>=n or j>=m )
        return khali;
    if( vis[i][j]==p )
        return dp[i][j];

    pii ret;
    ret.f= 0;
    ret.s= 0;

    if( type1[i]==type2[j] )
        ret= rec( i+1, j+1 ),
        ret.f+= labh[0][i]+labh[1][j],
        ret.s++;

    pii q1= rec( i+1, j );
    pii q2= rec( i, j+1 );

    if( q1.f<=q2.f )
    {
        if( q1.f<q2.f )
            q1.f=q2.f,
            q1.s=q2.s;
        else if( q1.f==q2.f and q1.s>q2.s )
            q1.f=q2.f,
            q1.s=q2.s;
    }

    if( ret.f<=q1.f )
    {
        if( ret.f<q1.f )
            ret.f=q1.f,
            ret.s=q1.s;
        else if( ret.f==q1.f and ret.s>q1.s )
            ret.f=q1.f,
            ret.s=q1.s;
    }

    vis[i][j]= p;

    return dp[i][j]= ret;
}

int main()
{
    khali.f= 0;
    khali.s= 0;

    int tc;
    cin>>tc;

    while(tc--)
    {
        p++;
        cin>>n;

        for( int i=0;i<n;i++ )
        {
            string s,t;
            cin>>s>>t;

            int d;
            cin>>d;

            labh[0][i]= d;

            type1[i]= t;
        }

        cin>>m;

        for( int i=0;i<m;i++ )
        {
            string s,t;
            cin>>s>>t;

            int d;
            cin>>d;

            labh[1][i]= d;

            type2[i]= t;
        }

        cout<< rec( 0,0 ).f <<" "<< rec( 0,0 ).s << endl;

        type1.clear();
        type2.clear();
    }
}
