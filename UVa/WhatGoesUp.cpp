#include <bits/stdc++.h>
#define inf INT_MAX
using namespace std;

vector <int> arr;
vector <int> v;

int main()
{
    int n;

    while(cin>>n)
        arr.push_back(n);

    int sz= arr.size();

    int L[sz+5],I[sz+5];

    I[0]= -inf;
    for(int i=1;i<=sz;i++)
        I[i]= inf;

    int LIS=1;

    for(int i=0;i<sz;i++)
    {
        int low=0,high=LIS;

        while(low<=high)
        {
            int mid= (low+high)/2;

            if(I[mid]< arr[i])
                low= mid+1;
            else
                high= mid-1;
        }

        I[low]= arr[i];
        L[i]= low;

        if(low > LIS)
            LIS=low;
    }

    cout<<LIS<<endl<<"-"<<endl;

    LIS++;
    int curr=inf;

    for(int i=sz-1;i>=0;i--)
    {
        if(LIS==1)
            break;
        if(arr[i]<curr and LIS-L[i]==1)
        {
            LIS--;
            curr=arr[i];
            v.push_back(arr[i]);
        }
    }

    reverse(v.begin(), v.end());
    sz=v.size();

    for(int i=0;i<sz;i++)
        cout<<v[i]<<endl;

}
