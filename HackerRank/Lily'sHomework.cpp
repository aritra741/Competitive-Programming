#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int arr[n], arr2[n], arrr[n];
    map<int, int> idx, idx2;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        arr2[i]=arr[i];
        arrr[i]= arr[i];
        idx[arr[i]]=i;
        idx2[arr[i]]=i;
    }

    sort( arr2, arr2+n );
    int cnt= 0;

    for(int i=0;i<n;i++)
    {
        if( arr[i]==arr2[i] )
            continue;

        cnt++;
        int temp= arr[i];

        swap( arr[i], arr[idx[ arr2[i] ]] );
        idx[ temp ]= idx[ arr2[i] ];
        idx[ arr2[i] ]= i;
    }

    sort( arr2, arr2+n, greater<int>() );

    int cnt2= 0;

    for(int i=0;i<n;i++)
    {
        if( arrr[i]==arr2[i] )
            continue;

        cnt2++;
        int temp= arrr[i];

        swap( arrr[i], arrr[idx2[ arr2[i] ]] );
        idx2[ temp ]= idx2[ arr2[i] ];
        idx2[ arr2[i] ]= i;
    }

    cout<<min(cnt, cnt2)<<endl;
}
