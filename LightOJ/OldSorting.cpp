#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int t=1; t<=tc; t++)
    {
        int n;
        cin>>n;
        int arr[n+1];
        arr[0]=0;
        for(int i=1; i<=n; i++)
            cin>>arr[i];

        int cnt=0;

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                int num=arr[j];
                if(num==j)
                    continue;

                swap( arr[num], arr[j] );
                cnt++;
            }
        }

        printf("Case %d: %d\n", t, cnt);

    }
}
