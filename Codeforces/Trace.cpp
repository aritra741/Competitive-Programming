#include <bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr, arr+n);

    double ans= 0.0;

    for(int i=n-1;i>=0;i-=2)
    {
        if(!i)
            ans+= pi*arr[i]*arr[i];
        else
            ans+=pi*( arr[i]*arr[i]-arr[i-1]*arr[i-1] );
    }

    cout<<setprecision(6)<<fixed<<ans<<endl;
}
