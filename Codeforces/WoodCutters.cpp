#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define x first
#define h second
using namespace std;

int main()
{
    int n;
    cin>>n;

    pll arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i].x>>arr[i].h;

    sort(arr, arr+n);

    int cnt=1;
    int nxt= arr[0].x;

    for(int i=1;i<n-1;i++)
    {
        if( arr[i].x-nxt>arr[i].h )
            nxt= arr[i].x, cnt++;
        else if( arr[i+1].x-arr[i].x>arr[i].h )
            nxt= arr[i].x+arr[i].h, cnt++;
        else
            nxt= arr[i].x;
    }

    if(n>1)
        cnt++;

    cout<<cnt<<endl;

}
