#include <bits/stdc++.h>
#define ll long long
#define inf 1e9
using namespace std;

ll arr[1010];

int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        int n,m;
        cin>>n>>m;

        ll mx= -1;
        ll sum= 0;

        for(int i=0;i<n;i++)
        {
            cin>>arr[i];

            sum+= arr[i];
            mx= max( mx, arr[i] );
        }

        cout<<"Case "<<t<<": ";

        if( m>=n )
        {
            cout<< mx <<endl;
            continue;
        }

        ll low= mx, high= sum, mid= (low+high)/2;
        int lim= (n+m-1)/m;

        for(int j=0;j<100;j++)
        {
            mid= (low+high)/2;
            int cnt= 0;
            ll till= 0;

            for(int i=0;i<n;i++)
            {
                if(arr[i]>mid)
                {
                    cnt= inf;
                    break;
                }

                if( till+arr[i]>mid )
                    cnt++, till= arr[i];
                else
                    till+=arr[i];
            }

            if( cnt<m )
                high= mid;
            else
                low= mid;
        }

        cout<< high <<endl;
    }
}
