#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int p=0;p<n;p++)
            cin>>arr[p];
        int cnt=0;
        for(int h=0;h<n;h++)
            {
                long long sum=0;
                long long prod=1;
            for(int j=h;j<n;j++)
                {
                    sum+=arr[j];
                    prod*=arr[j];
                    if(sum==prod)
                        cnt++;

                }
            }
cout<<cnt<<endl;
    }
}
