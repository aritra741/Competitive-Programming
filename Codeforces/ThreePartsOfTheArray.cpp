#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main()
{
    int n;
    cin>>n;
    ull arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    ull left=0,right=0;
    ull ans=0;

    for(int i=0,j=n-1;;)
    {
        if(i>=j)
            break;
        int u=arr[i];
        int v=arr[j];
        if(left<right)
            left+=u;
        else if(right<left)
            right+=v;
        else if(right==left)
        {
            ans=left;
            left+=u;
            right+=v;
                }
        if(right==left)
            {
                ans=left;
                i++;
                j--;
            }
        else if(left>right)
            j--;
        else if(right>left)
            i++;


    }

    cout<<ans;

}
