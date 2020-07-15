#include <bits/stdc++.h>
#define inf 1e9
using namespace std;

bool pal[1007][1007];
int cuts[1007];
int dp[1007][1007];
int vis[1007][1007];
string s;

void calcPal()
{
    for(int i=0; i<s.size(); i++)
        pal[i][i]= 1;

    for(int len=2; len<=s.size(); len++)
    {
        for(int i=0; i<=s.size()-len; i++)
        {
            int j= i+len-1;

            if(len==2)
                pal[i][j]= (s[i]==s[j]);
            else
            {
                pal[i][j]= ( (s[i]==s[j]) & pal[i+1][j-1] );
            }
        }
    }
}

void calcCuts( )
{
    for(int i=0; i<s.size(); i++)
    {
        if( pal[0][i] )
            cuts[i]= 0;
        else
        {
            cuts[i]= inf;
            for(int j=0; j<i; j++)
                if( pal[j+1][i] and cuts[j]+1<cuts[i] )
                    cuts[i]= cuts[j]+1;
        }
    }
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1; t<=tc; t++)
    {
        cin>>s;

        calcPal();
        calcCuts();

        cout<<"Case "<<t<<": "<< cuts[s.size()-1]+1 <<endl;
    }
}
