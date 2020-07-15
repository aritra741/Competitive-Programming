#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;

bool cmp( const pll &a, const pll &b )
{
    if(a.x==b.x)
        return a.y>b.y;
    return a.x<b.x;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        scanf("%lld", &n);
        pll arr[n];
        for(int i=0;i<n;i++)
        {
            scanf("%lld %lld", &arr[i].x, &arr[i].y);
        }
        sort(arr, arr+n, cmp);

        for(int i=0;i<n;i++)
            printf("%lld %lld\n", arr[i].x, arr[i].y);


    }
}

