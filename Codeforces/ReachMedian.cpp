#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n, med;

    scanf("%lld %lld", &n, &med);

    ll arr[n];

    for(int i=0;i<n;i++)
        scanf("%lld", &arr[i]);

    sort( arr, arr+n );

    int pos= n/2;
    ll tot=abs( med-arr[pos] );

    for(int i=pos+1; i<n; i++)
    {
        if(med>arr[i])
            tot+= med-arr[i];
        else
            break;
    }

    for(int i=pos-1; i>=0; i--)
    {
        if(med<arr[i])
            tot+= arr[i]-med;
        else
            break;
    }

    printf("%lld\n", tot);


}
