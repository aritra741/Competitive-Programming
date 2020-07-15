#include<bits/stdc++.h>
using namespace std;

int arr[107], freq[107];
char ans[107];
map<int,int>mp;

int main()
{
    int n;
    cin>>n;

    for( int i=0; i<n; i++ )
        cin>> arr[i], mp[ arr[i] ]++;

    for( auto x: mp )
        freq[ x.second ]++;

    if( freq[1]&1 )
    {
        int f= 0;

        for( int i=3;i<=n;i++ )
        {
            if( freq[i] )
            {
                f= i;
                break;
            }
        }

        if(!f)
            return cout<<"NO\n", 0;

        cout<<"YES\n";
        int tot= (1+freq[1])/2;
        int dibo1= freq[1]/2;
        int rem1= tot-freq[1]/2;

        for( int i=0; i<n; i++ )
        {
            if( dibo1 and mp[arr[i]]==1 )
                dibo1--, ans[i]= 'B';
            else if( rem1 and mp[ arr[i] ]==f )
                rem1--, ans[i]= 'B', mp[ arr[i] ]++;
        }

        for( int i=0;i<n;i++ )
            if( ans[i]!='B' )
                ans[i]= 'A';
    }

    else
    {
        cout<<"YES\n";
        int tot= freq[1]/2;

        for( int i=0; i<n; i++ )
        {
            if( tot and mp[arr[i]]==1 )
                tot--, ans[i]= 'B';
            else
                ans[i]= 'A';
        }
    }

    cout<< ans <<endl;
}
