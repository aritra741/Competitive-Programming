#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        int arr[n+5];

        for( int i=2;i<=n+1;i++ )
            cin>>arr[i];

        sort( arr+2, arr+n+2 );

        int i= 1,j= 2;

        while( i<=n+1 and j<=n+1 )
        {
            if( arr[j]<=j-1 )
            {
                i= j;
                j++;
                continue;
            }

            j++;
        }

        cout<< i <<endl;
    }
}
