#include <bits/stdc++.h>
#define d(x) cout<<x<<endl;
using namespace std;
int main()
{

        int n,k;
        cin>>n>>k;
        int arr[n+1];
        int flag[n+1];
        map<int,int> cap;
        memset(flag, 0, sizeof(flag));
        memset(arr, 0, sizeof(arr));
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }
        int temp;
        for(int i=0;i<k;i++)
        {
            cin>>temp;
            flag[temp]=1;
            cap[temp]=arr[temp];
        }
        int ans=0;
        for(int i=1;i<n;i++)
            if(flag[i]==0 && flag[i+1]==0)
                ans+=arr[i]*arr[i+1];
        d(ans);

       if(flag[1]==0 && flag[n]==0)
                ans+=arr[1]*arr[n];
        d(ans);
        for(int i=0;i<k;i++)
            for(int j=1;j<=n;j++)
                if(flag[j]==0)
                    ans+=cap[i]*arr[j];

    d(ans);
        for(int i=0;i<k;i++)
            for(int j=0;j<k;j++)
                if(i!=j)
                    ans+=cap[i]*cap[j];


        cout<<ans;






}
