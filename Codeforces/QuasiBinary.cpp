#include <bits/stdc++.h>
#define inf 1e7
using namespace std;

vector<int> v, ans;

int dp[1000007];
bool vis[1000007];
int n, num;

int rec( int tot )
{
    if(tot==num)
        return 0;
    if(vis[tot])
        return dp[tot];

    int q1=inf, q2;

    int ans= inf;

    for(int i=0;i<n;i++)
    {
        if( tot+v[i]<=num )
            ans= min( ans, 1+rec( tot+v[i] ) );
    }

    vis[tot]= 1;

    return dp[tot]= ans;
}


void print(int tot)
{

    if(tot==num)
        return;

    int ans=inf,ind=0;

    for(int i=0;i<n;i++)
    {
        if(tot+v[i]<=num){
            if( dp[tot+v[i]]<ans){
                ind=i;
                ans=dp[tot+v[i]];
            }
        }
    }
    printf("%d ",v[ind]);
    print(tot+v[ind]);
}

bool quasi( int n )
{
    int temp;

    while(n>0)
    {
        temp=n%10;
        if(temp>1)
            return 0;
        n/=10;
    }

    return 1;
}

int main()
{
    for(int i=1; i<=1000000; i++)
        if( quasi(i) )
            v.push_back(i);

    n= v.size();

    scanf("%d", &num);
    printf("%d\n", rec( 0 ) );
    print(0);
}
