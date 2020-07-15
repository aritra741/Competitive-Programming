#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    int arr[n];

    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    ll tot= 0;
    int idx= n/2;

    for(int i=0; i<idx; i+=m)
    {
        ll temp= arr[idx]-arr[i];
        temp*=2;
        tot+=temp;
    }

    for(int i=n-1; i>idx; i-=m)
    {
        ll temp= arr[i]-arr[idx];
        temp*=2;
        tot+=temp;
    }

    printf("%lld\n", tot);
}
