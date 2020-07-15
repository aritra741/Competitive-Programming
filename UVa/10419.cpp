#include<bits/stdc++.h>
using namespace std;

int arr[301];
bool ok[350];
bool dp[150][1007][17];
int vis[150][1007][17];
vector<int> ans;
int j,n,p,t;

bool cmp( int a, int b )
{
    string s,t;
    stringstream ss, ss2;
    ss<<a;
    ss2<<b;
    ss>>s;
    ss2>>t;

    return s<=t;
}

void sieve()
{
    arr[j++]= 2;

    for( int i=3;i<350;i+= 2 )
    {
        if(!ok[i])
        {
            if(i<=300)
                arr[j++]= i,
                arr[j++]= i;

            for( int k=i*2;k<350;k+= i )
                ok[k]= 1;
        }
    }
}

bool rec( int i, int tot, int nisi )
{
    if( tot>n )
        return 0;
    if( nisi>t )
        return 0;
    if( tot==n )
    {
        if(nisi==t)
            return dp[i][tot][nisi]= 1;
        return 0;
    }
    if( nisi==t )
    {
        if(tot==n)
            return dp[i][tot][nisi]= 1;
        return 0;
    }
    if(i>=j)
        return 0;
    if( vis[i][tot][nisi]==p )
        return dp[i][tot][nisi];

    bool ret= 0;

    ret|= rec( i+1, tot+arr[i], nisi+1 );

    if(!ret)
        ret|= rec( i+1, tot, nisi );

    vis[i][tot][nisi]= p;

//    if( ret )
//        cout<<i<<" "<<tot<<" "<<nisi<<endl;

    return dp[i][tot][nisi]= ret;
}

void gen( int i, int tot, int nisi )
{
    if( i>=j or tot>n or nisi>=t )
        return;
    if( vis[i+1][tot+arr[i]][nisi+1]==p and dp[i+1][tot+arr[i]][nisi+1] )
    {
//        cout<<arr[i]<<" "<<tot<<" "<<nisi<<endl;
        ans.push_back( arr[i] );
        gen( i+1, tot+arr[i], nisi+1 );
    }
    else if( vis[i+1][tot][nisi]==p and dp[i+1][tot][nisi] )
    {
        gen( i+1, tot, nisi );
    }
}

int main()
{
    sieve();
//    cout<<j<<endl;
    sort( arr, arr+j, cmp );
    int tc= 1;

    while( scanf("%d %d", &n, &t)==2 and n and t )
    {
        p++;
        printf("CASE %d:\n", tc++);

        if( !rec( 0, 0, 0 ) )
            printf("No Solution.\n");
        else
        {
            gen(0,0,0);
            if( ans.size() )
                printf("%d", ans[0]);

            int sum= ans.size()?ans[0]:0;

            for( int i=1;i<ans.size();i++ )
                printf("+%d", ans[i]), sum+= ans[i];

            if( sum )
                printf("+");
            printf("%d\n", n-sum);

            ans.clear();
        }
    }
}
