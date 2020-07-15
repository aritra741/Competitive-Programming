#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll arr1[3*100005];
ll arr2[3*100005];

int main()
{
    int n, m;
    cin>>n;

    ll sum=0;

    for(int i=0; i<n; i++)
        {
            scanf("%lld", &arr1[i]);
            sum+=arr1[i];
        }

    cin>>m;

    for(int i=0; i<m; i++)
        {
            scanf("%lld", &arr2[i]);
            sum-=arr2[i];
        }

    if(sum)
    {
        cout<<"-1"<<endl;
        return 0;
    }

    int i,j,cnt=0;
    ll a=arr1[0], b=arr2[0];

    for(i=1, j=1; i<n or j<m;)
    {
        if( a>b )
            b+=arr2[j], j++;
        else if( b>a )
            a+=arr1[i], i++;
        else
            a=arr1[i], b=arr2[j], i++, j++, cnt++;

    }

    if(a==b)
        cnt++;

    cout<<cnt<<endl;

}
