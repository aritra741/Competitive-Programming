#include<bits/stdc++.h>
#define mx 200007
#define ll long long
#define ff first
#define ss second
#define pii pair<int,int>
using namespace std;

pii arr[mx];
vector<int>v1,v2;
ll sum1= 0, sum2= 0;

int main()
{
    int n;
    cin>>n;

    for( int i=0;i<n;i++ )
        cin>> arr[i].ff, arr[i].ss= i+1;

    sort( arr, arr+n );

    int i=0, j= n-1;
    for( ;i<j;i++,j-- )
        v1.push_back( arr[i].ff ),
        v1.push_back( arr[j].ff );

    if( i==j )
        v1.push_back( arr[i].ff );

    for( int i=1;i<n;i++ )
        sum1+= abs( v1[i]-v1[i-1] );

    i=0, j= n-1;

    for( ;i<j;i++,j-- )
        v2.push_back( arr[j].ff ),
        v2.push_back( arr[i].ff );

    if( i==j )
        v2.push_back( arr[i].ff );

    for( int i=1;i<n;i++ )
        sum2+= abs( v2[i]-v2[i-1] );

    if( sum1>sum2 )
    {
        cout<<sum1<<endl;

        int i=0, j= n-1;
        for( ;i<j;i++,j-- )
            cout<<arr[i].ss<<" "<<arr[j].ss<<" ";
        if( i==j )
            cout<<arr[i].ss<<endl;
    }
    else
    {
        cout<<sum2<<endl;

        int i=0, j= n-1;
        for( ;i<j;i++,j-- )
            cout<<arr[j].ss<<" "<<arr[i].ss<<" ";
        if( i==j )
            cout<<arr[i].ss<<endl;
    }

}
