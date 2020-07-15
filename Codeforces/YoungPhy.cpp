#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool flag=0;
    int n;cin>>n;
    int arr[n][3];
    int sum[3];
    memset(sum, 0, sizeof(sum));
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
for(int i=0;i<3;i++)
       {
           for(int j=0;j<n;j++)
                sum[i]+=arr[j][i];

if(sum[i]!=0)
    flag=1;
}

if(flag)
    cout<<"NO";
else cout<<"YES";
}


