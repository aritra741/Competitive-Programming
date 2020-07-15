#include <bits/stdc++.h>
#define ll long long
using namespace std;

int tp( ll arr[] )
{
    if(!arr[0])
        return 4;
    if( arr[0]==arr[3] )
        return 1;
    if(arr[0]==arr[1] and arr[2]==arr[3])
        return 2;
    if(arr[0]+arr[1]+arr[2]>arr[3])
        return 3;
    return 4;
}

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        ll arr[4];

        for(int i=0;i<4;i++)
            cin>>arr[i];
        sort(arr, arr+4);

        int type= tp(arr);

        if(type==1)
            cout<<"square\n";
        else if(type==2)
            cout<<"rectangle\n";
        else if(type==3)
            cout<<"quadrangle\n";
        else
            cout<<"banana\n";
    }
}
