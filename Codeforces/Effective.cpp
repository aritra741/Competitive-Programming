#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int vas=0,pet=0;
    long long int n;cin>>n;
    long long int arr1[n];
    map <long long int, long long int> pos;
    for(long long int i=0;i<n;i++)
    {
        cin>>arr1[i];
        pos[arr1[i]]=i+1;
    }
    long long int m;
    cin>>m;
    long long int temp;
    while(m--)
    {
        cin>>temp;
        vas+=pos[temp];
        pet+=n-pos[temp]+1;
    }
    cout<<vas<<" "<<pet;
}
