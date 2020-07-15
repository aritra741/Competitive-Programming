#include <bits/stdc++.h>
#define ll long long
#define m 1000000007
using namespace std;

int sz,l,r;
ll dp[200007][3];
bool vis[200007][3];

ll rec( int n, int rem )
{
    if( n==1 )
    {
        ll L= l-1, R=r;
        if( rem==0 )
            return R/3-L/3;
        if( rem==2 )
            return (R+1)/3-(L+1)/3;
        return (R+2)/3-(L+2)/3;
    }

    if( vis[n][rem] )
        return dp[n][rem];

    ll q1= (rec( n/2, 0 )%m*rec( n-n/2, rem )%m)%m;
    ll q2= (rec( n/2, 1 )%m*rec( n-n/2, (3+rem-1)%3 )%m)%m;
    ll q3= (rec( n/2, 2 )%m*rec( n-n/2, (3+rem-2)%3 )%m)%m;

    vis[n][rem]= 1;

    return dp[n][rem]= (q1+(q2+q3)%m)%m;
}

int main()
{
    cin>>sz>>l>>r;

    cout<< rec( sz, 0 ) <<endl;
}
