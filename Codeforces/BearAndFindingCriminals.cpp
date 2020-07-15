#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    int i= k-2, j= k;
    int cnt= (arr[k-1])?1:0;

    while(i>=0 or j<n)
    {
        if( i<0 and j<n and arr[j] )
            cnt++;
        else if( j>=n and i>=0 and arr[i] )
            cnt++;
        else if( arr[i] and arr[j] )
            cnt+=2;
        i--, j++;
    }

    cout<< cnt <<endl;
}

