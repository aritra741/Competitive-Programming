#include<bits/stdc++.h>
using namespace std;

int ans[100007];

int main()
{
    int n;
    cin>>n;

    int arr[n+5];
    memset( ans, -1, sizeof(ans) );

    map<int,int>cnt;
    int x;

    for( int i=0;i<n;i++ )
        cin>>arr[i], cnt[arr[i]]++;

    bool ok= 1;
    int now= 0;
    for( int i=0;i<n;i++ )
    {
        while( cnt[now] )
            now++;

        if( ans[i]==-1 )
            ans[i]= now++;

        cnt[arr[i]]--;

        if( !cnt[arr[i]] )
            ans[i+1]= arr[i], now= max( arr[i]+1, now );
    }

    for( int i=0;i<n;i++ )
        cout<< ans[i] <<" ";
}
