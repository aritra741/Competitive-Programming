#include <bits/stdc++.h>
using namespace std;

int kadane(int arr[], int n)
{
    int mxsum=0;
    int sum=0;
    int val=-1;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum<0)
            sum=0;

        if(mxsum<sum)
            {
                mxsum=sum;
                val=i;
            }
    }

    if(val!=-1)
    return mxsum;

    mxsum=arr[0];

    for(int i=1;i<n;i++)
    {
        if(arr[i]>mxsum)
            mxsum=arr[i];
    }

    return mxsum;
}

int main()
{
    int MAX=INT_MIN;
    int n;
    int sum;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    int temp[n];
    for(int left=0;left<n;left++)
    {
        memset(temp, 0, sizeof(temp));
        for(int right=left;right<n;right++)
        {

            for(int i=0;i<n;i++)
                temp[i]+=arr[i][right];
            sum=kadane(temp, n);
            if(sum>MAX)
                MAX=sum;
        }

    }
    cout<<MAX<<endl;

}
