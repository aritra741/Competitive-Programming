#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        int n,p,q;
        scanf("%d %d %d", &n, &p, &q);
        int arr[n];
        for(int j=0;j<n;j++)
        {
            scanf("%d", &arr[j]);
        }
        sort(arr, arr+n);
        int tot=0;
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            if(cnt==p)
                break;
            if(tot+arr[j]<=q && cnt<p)
            {
                tot+=arr[j];
                cnt++;
            }
        }
        printf("Case %d: %d\n", i, cnt);
    }
}
