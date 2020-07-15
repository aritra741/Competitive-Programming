#include <bits/stdc++.h>
#define ll long long
using namespace std;

int arr[4];

int main()
{
    for(int i=0;i<4;i++)
        cin>>arr[i];

    if( arr[0]!=arr[3] )
    {
        cout<<"0";
        return 0;
    }

    if( arr[2] and !arr[0] and !arr[3] )
    {
        cout<<"0";
        return 0;
    }

    cout<<"1";
}
