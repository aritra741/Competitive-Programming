#include <bits/stdc++.h>
#define pii pair <int, int>
using namespace std;
int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        pii arr[n], arr1[n];

        for(int i=0;i<n;i++)
        {
            int s,t;
            cin>>s>>t;

            arr[i].first=s;
            arr[i].second=t;
            arr1[i].first=t;
            arr1[i].second=s;
        }

        sort( arr, arr+n );
        sort( arr1, arr1+n );

        int mx= -1;

        int cnt=0;

     //   cout<<endl;

      //  cout<<arr[0].first<<" "<<arr1[0].first<<endl;

        for(int i=0, j=0;i<n and j<n;)
        {
            if( arr[i].first<=arr1[j].first )
                cnt++,i++;
            else
                j++, cnt--;

            mx= max( mx, cnt );

           // cout<<arr[i].first<<" "<<arr1[j].first<<" "<<cnt<<endl;
        }

        cout<<mx<<endl;

    }
}
