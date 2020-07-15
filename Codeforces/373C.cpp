#include<bits/stdc++.h>
using namespace std;

int arr[500007];
bool baad[500007];

int main()
{
    int n;
    cin>>n;

    for( int i=0;i<n;i++ )
        cin>>arr[i];

    sort( arr, arr+n );

    int bhitore= 0;

    for( int i=0, j=n/2;i<n/2 and j<n; )
    {
        if( baad[i] )
        {
            i++;
            continue;
        }
        if( baad[j] )
        {
            j++;
            continue;
        }

        if( arr[i]*2<=arr[j] )
            bhitore++, baad[i]= 1, baad[j]= 1, i++, j++;
        else
            j++;
    }

    cout<<n-bhitore<<endl;
}
