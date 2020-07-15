#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    int mx=0;
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
        {
            int g=0;
            for(int l=i; l<=j; l++)
            {
                if(arr[l]==1)
                    g--;
                else
                    g++;
            }
            mx=max(mx, sum+g);

        }

    cout<<mx;
}
