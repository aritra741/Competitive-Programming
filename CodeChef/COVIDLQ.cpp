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

        for( int i=0;i<n;i++ )
            cin>>arr[i];

        int last= -1;
        bool f= 1;

        for( int i=0;i<n;i++ )
        {
            if( arr[i] )
            {
                if( last==-1 )
                    last= i;
                else if( i-last<6 )
                {
                    f= 0;
                    break;
                }

                last= i;
            }
        }

        if(f)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
