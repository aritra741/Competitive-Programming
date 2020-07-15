#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

pii arr[1000007];
char ans[1000007];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for( int i=0;i<n;i++ )
    {
        int p,q;
        cin>>p>>q;

        arr[i].first= 500-p;
        arr[i].second= i;
    }

    sort( arr, arr+n );

    int i=0, j= n-1;
    int diff= 0;

    for( ;i<n and i<j; )
    {
        cout<<arr[i].second<<" "<<arr[j].second<<" "<<diff<<endl;
        if( diff+arr[i].first>500 )
            diff+= arr[j].first, ans[ arr[j].second ]='G', j--;
        else
            diff+= arr[i].first, ans[ arr[i].second ]='A', i++;
    }

    if( i==j and !ans[ arr[i].second ] )
    {
        if( diff+arr[i].first>500 )
            ans[ arr[i].second ]= 'G';
        else
            ans[ arr[i].second ]= 'A';
    }

    for( int i=0;i<n;i++ )
        cout<< ans[i];

    cout<<endl;
}
