#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);

    while(tc--)
    {
        int n;
        scanf("%d", &n);

        int arr[n+5];

        for( int i=0; i<n; i++ )
            scanf("%d", &arr[i]);

        ll odd= 0, ev= 0, lastev= -1;
        ll lasteragerev= -1;
        ll ans= 0;

        for( int i=0; i<n; i++ )
        {
            ll ekhon= 0;

            if(arr[i]&1)
            {
                if( lastev>-1)
                {
                    if( arr[lastev]%4==0 )
                    {
                        ekhon= i+1;
                    }
                    else if( lasteragerev>-1 )
                    {
                        ekhon= lasteragerev+1;
                        ekhon+= i-lastev;
                    }
                    else
                    {
                        ekhon= i-lastev;
                    }
                }

                else
                {
                    ekhon= i+1;
                }

                odd++;
            }
            else
            {
                if( arr[i]%4==0 )
                    ekhon= i+1;
                else if( lastev>-1 )
                    ekhon= lastev+1;

                ev++;
                lasteragerev= lastev;
                lastev= i;
            }

            ans+= ekhon;
        }

        printf("%lld\n", ans);
    }
}
