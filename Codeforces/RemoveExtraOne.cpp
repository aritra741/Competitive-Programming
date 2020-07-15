#include <bits/stdc++.h>
using namespace std;

int arr[100007];
map<int,int> mp;
map<int,int> ::iterator it;

int main()
{
    int n;
    cin>>n;

    if(n==1)
        return cout<<"1", 0;

    int mx= 0;
    for( int i=0; i<n; i++ )
    {
        scanf("%d", &arr[i]);

        if( arr[i]>mx )
            mp[arr[i]]= -1,
            mx= arr[i];
    }

    int mxSoFar= max( arr[0], arr[1] );
    int secMxSoFar= min( arr[0], arr[1] );
    mx= 0;

    for( int i=1;i<n;i++ )
    {
        if( arr[i]<mxSoFar and arr[i]>=secMxSoFar )
            mp[ mxSoFar ]++,
            mx= max( mx, mp[mxSoFar] );
        if( arr[i]>mxSoFar )
            secMxSoFar= mxSoFar,
            mxSoFar= arr[i];
        else if( arr[i]<mxSoFar and arr[i]>secMxSoFar )
            secMxSoFar= arr[i];
    }

    vector<int> v;

    for( int i=1;i<=n;i++ )
        if( mp[i]==mx )
            return cout<<i<<endl, 0;

    printf("1");
}
