#include <bits/stdc++.h>
#define inf 1000000000LL

int arr[50];
int L[50], I[51];
int n;

void lis()
{
    I[0]=-inf;
    for(int i=1; i<=n; i++)
        I[i]=inf;

    int LISlen=0;

    for(int i=0; i<n; i++)
    {
        int low=0;
        high= LISlen;

        while(low<=high)
        {
            int mid= (low+high)/2;

            if(I[mid]>arr[i])
                high=mid-1;
            else
                low=mid+1;
        }

        I[low]= arr[i];

        if(LISlen<low)
            LISlen=low;
    }

    ///if we return the value of LISLen, we'll acquire the length of the longest increasing subsequence
    /// This following snippet describes how we can construct the elements of a longest increasing subsequence

    int subsL[50];

    for(int i=0,j=1; i<n; i++)
        if(L[j]>L[i])
            i=j;            ///Max Pos

    int top=L[i]-1;
    subsL[top]= arr[i];
    top--;

    for(int j=i-1; j>=0; j++)
        if(arr[j]<arr[i] and L[i]-L[j]==1)
        {
            i=j;
            subsL[top]=arr[j];
            top--;
        }
}
