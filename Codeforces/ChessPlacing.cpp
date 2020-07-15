#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int pos[n+1]={0};
    int odd=0;
    int even=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i] & 1)
            odd++;
        else
            even++;
        pos[i+1]=1;

    }
    int sum=0;
    if(odd>even)
    {
        for(int i=0;i<n;i++)
        {
            if(! (arr[i]&1))
            for(int j=i+1;j<=n;j++)
            if( !pos[j+1] && (arr[j]%2) )
                sum+=(j-i);
        }
    }
    else
        {
        for(int i=0;i<n;i++)
        {
            if(arr[i]&1)
            for(int j=i+1;j<=n;j++)
            if( !pos[j] )
                sum+=(j-i);
        }
    }
}
