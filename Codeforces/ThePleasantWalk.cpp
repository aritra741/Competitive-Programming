#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    int ans= 1, cnt= 1;

    for(int i=1;i<n;i++)
    {
        if(arr[i]!=arr[i-1])
            cnt++;
        else
            ans= max(ans, cnt), cnt= 1;
    }

    ans= max(ans, cnt);

    cout<<ans<<endl;
}
