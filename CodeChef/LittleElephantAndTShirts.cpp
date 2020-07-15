#include <bits/stdc++.h>
#define ll long long
#define m 1000000007
using namespace std;

int dp[1030][101];
bool vis[1030][101];
vector<int> cap[101];
int done;

int rec( int mask, int i )
{
    if(mask==done)
        return 1;
    if(i>100)
        return 0;
    if( vis[mask][i] )
        return dp[mask][i];

    ll ways= rec( mask, i+1 );

    for( int j=0;j<cap[i].size();j++ )
        if( !(mask&(1<<cap[i][j])) )
            ways=(ways%m+rec( mask|(1<<cap[i][j]), i+1 )%m)%m;
    vis[mask][i]= 1;

    return dp[mask][i]= ways%m;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        done= (1<<n)-1;
        getchar();
        for(int i=0; i<n; i++)
        {
            string s;
            getline( cin, s );
            stringstream ss;
            int t;
            ss<<s;

            while( ss>>t )
                cap[t].push_back(i);
        }

        cout<< rec( 0, 1 ) <<endl;

        for(int i=0;i<=100;i++)
            cap[i].clear();
        memset(vis,0,sizeof(vis));
    }
}

