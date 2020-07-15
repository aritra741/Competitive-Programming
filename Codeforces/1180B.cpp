#include<bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define mx 100007
using namespace std;

pii arr[mx];
int ans[mx];
int cnt;

int main()
{
    int n;
    cin>>n;

    for( int i=0;i<n;i++ )
        cin>> arr[i].ff, arr[i].ss= i,
        arr[i].ff= (arr[i].ff>=0)? -arr[i].ff-1:arr[i].ff,
        cnt= (arr[i].ff<0)?cnt+1:cnt;

    if( cnt&1 )
    {
        sort( arr, arr+n );

        for( int i=0;i<n;i++ )
        {
            if( arr[i].ff<0 )
            {
                arr[i].ff= -arr[i].ff-1;
                break;
            }
        }
    }

    for( int i=0;i<n;i++ )
        ans[ arr[i].ss ]= arr[i].ff;

    for( int i=0;i<n;i++ )
        cout<< ans[i] <<" ";
}

