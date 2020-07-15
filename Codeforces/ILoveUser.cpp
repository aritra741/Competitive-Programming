#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int num[n];
    int mx=-1,mn=10005,amz=0;
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
        if(num[i]>mx)
        {
            mx=num[i];
            amz++;
        }
        if(num[i]<mn)
        {
            mn=num[i];
            amz++;
        }

    }
    amz-=2;
    cout<<amz;
}
