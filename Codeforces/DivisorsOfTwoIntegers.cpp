#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort( arr, arr+n );

    set<int> dv;

    int mx= arr[n-1];

    for(int i=0;i<n;i++)
        {
            int sz= dv.size();
            if( arr[n-1]%arr[i]==0 )
                dv.insert(arr[i]);

            if( dv.size()>sz )
                arr[i]= -1;
        }

    sort( arr, arr+n );

    cout<< mx <<" "<< arr[n-1] <<endl;
}
