#include <bits/stdc++.h>
#define MX 1000007
#define inf 1000000000LL
using namespace std;

int arr[MX], I[MX];

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>arr[i];

    I[0]=-inf;
    for(int i=1;i<=n;i++)
        I[i]=inf;

    int LIS=1;

    for(int i=0;i<n;i++)
    {
        int low=0, high=LIS;

        while(low<=high)
        {
            int mid=(low+high)/2;

            if(arr[i]>I[mid])
                low=mid+1;
            else
                high=mid-1;
        }

        I[low]=arr[i];

        if(low>LIS)
            LIS=low;
    }

    cout<<LIS<<endl;
}
