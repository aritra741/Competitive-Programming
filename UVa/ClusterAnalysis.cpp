#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        int n,k;
        scanf("%d %d", &n, &k);

        int arr[n];

        for(int i=0;i<n;i++)
        {
            scanf("%d", &arr[i]);
        }

        sort(arr, arr+n);

        int cnt=1;

        for(int i=1;i<n;i++)
            if(arr[i]-arr[i-1]>k)
                cnt++;

        printf("Case #%d: %d\n", t, cnt);
    }
}
