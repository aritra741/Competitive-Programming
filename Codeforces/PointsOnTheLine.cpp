#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    int arr[n];

    for(int i=0; i<n; i++)
        cin>>arr[i];

    sort(arr, arr+n);

    int cnt= 1, mx= 0, l= 0;

    for(int i=1; i<n; i++)
    {
        if(arr[i]-arr[l]<=k and l!=i)
            cnt++;
        else if(l!=i)
            mx= max(mx, cnt), cnt=(cnt==1)? 1: cnt-1, l++, i--;
    }

    mx= max(mx, cnt);

    cout<<n-mx<<endl;
}
