#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int t=1;t<=tc;t++)
    {
        int n;
        cin>>n;
        int arr[n+1];
        arr[0]=2;
        int cnt=0;
        for(int i=1;i<=n;i++)
            {
                cin>>arr[i];
                int add=ceil( (double)(arr[i]-arr[i-1])/5.0 );
                cnt+=add;

            }

        cout<<"Case "<<t<<": "<<cnt<<endl;
    }
}
