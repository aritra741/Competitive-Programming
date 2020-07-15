#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int arr[m+1];

    for(int i=0;i<=m;i++)
    {
        cin>>arr[i];
    }

    int ans=0;
    for(int j=0;j<m;j++){
    bitset <24> num( arr[j] ), fed( arr[m] );
    bitset <24> res= num ^ fed;
    int cnt=0;
    for(int i=0;i<24;i++)
        if(res[i]==1)
            cnt++;
    if(cnt<=k)
        ans++;
    }

    cout<<ans<<endl;
}
