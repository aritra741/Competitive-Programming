#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n+5], pos[n+5];

    for( int i=0;i<n;i++ )
        cin>>arr[i], pos[ arr[i] ]= i;

    map<int,int>mp;
    int ans= 1;

    for( int i=0;i<n;i++ )
    {
        int p;
        cin>>p;

        int curr= i-pos[p];
        if(curr<0)
            curr+=n;

        mp[ curr ]++;
        ans= max( ans, mp[ curr ] );
    }

    cout<< ans <<endl;
}
