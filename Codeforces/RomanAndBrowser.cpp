#include <bits/stdc++.h>
using namespace std;

int arr[107];

int main()
{
    int p= 0, neg= 0;
    int n,k;
    cin>>n>>k;

    for(int i=0;i<n;i++)
        cin>>arr[i],
        p= (arr[i]==-1)? p:p+1,
        neg= (arr[i]==-1)? neg+1:neg;

    int ans= 0;

    for(int i=0;i<k;i++)
    {
        int tmpp= p, tmpn= neg, tmp= 0;

        for(int j=i;j<n;j+=k)
        {
            if(arr[j]==-1)
                tmpn--;
            else
                tmpp--;
        }

        tmp= abs( tmpp-tmpn );
        ans= max(ans, tmp);
    }

    cout<< ans <<endl;
}
