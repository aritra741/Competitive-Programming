#include <bits/stdc++.h>
using namespace std;

int arr[5007];

int main()
{
    int n;
    cin>>n;

    for( int i=0; i<n; i++ )
        cin>> arr[i];

    sort( arr, arr+n );

    int cnt= 0, i=0, j=1;

    for(; i<n and j<n; )
    {
        if( i==j )
        {
            j++;
            continue;
        }

        if( arr[j]>arr[i] )
            i++, j++, cnt++;
        else
            j++;
    }

    cout<< n-cnt <<endl;
}
