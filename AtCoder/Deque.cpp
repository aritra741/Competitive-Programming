#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[3007][3007];
bool vis[3007][3007];
int arr[3007];

ll pref[100007];

int main()
{
    int n;
    cin>>n;

    for( int i=0;i<n;i++ )
        cin>> arr[i];

    dp[0]= 1;

    for( int i=0;i<n;i++ )
        for( int k )
}
