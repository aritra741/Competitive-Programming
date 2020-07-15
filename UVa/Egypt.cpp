#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[3];

    while(cin>>arr[0]>>arr[1]>>arr[2] and arr[0] and arr[1] and arr[2])
    {
        sort(arr, arr+3);

        if( arr[0]*arr[0]+arr[1]*arr[1]==arr[2]*arr[2] )
            cout<<"right\n";
        else
            cout<<"wrong\n";
    }
}
