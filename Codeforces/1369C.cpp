#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n,k;
        cin>>n>>k;

        int arr[n+5];

        for( int i=0; i<n; i++ )
            cin>>arr[i];

        sort( arr, arr+n, greater<int>() );

        int val[k+5];

        for( int i=0;i<k;i++ )
            cin>>val[i];

        sort( val, val+k );

        ll ans= 0;
        int j= 0;

        for( int i=0;i<k;i++ )
            if( val[i]==1 )
                ans+= arr[j++]*2LL, arr[j-1]= -2e9;

        int baki= k-j;

        for( int i=j;i<k;i++ )
            ans+= arr[j++], arr[j-1]= -2e9;

        j= 0;

        for( int i=0;i<k;i++ )
        {
            if( val[i]==1 )
                continue;

            int cnt= 0;

            for( ;j<n and val[i]>2;j++ )
            {
                if( arr[j]==-2e9 )
                    continue;
                cnt++;
                arr[j]= -2e9;
                if( cnt==val[i]-2 )
                    break;
            }

            for( ;j<n;j++ )
            {
                if( arr[j]==-2e9 )
                    continue;
                ans+= arr[j];
                arr[j]= -2e9;
                break;
            }
        }

        cout<<ans<<endl;
    }
}
