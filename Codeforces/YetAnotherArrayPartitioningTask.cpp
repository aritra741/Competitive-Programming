#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    pii arr[n];

    for(int i=0; i<n; i++)
    {
        cin>>arr[i].first;
        arr[i].second= i+1;
    }

    sort( arr,arr+n );
    reverse( arr, arr+n );

    vector<int> idx;

    ll ans= 0;
    for(int i=0; i<m*k; i++)
    {
        ans+= arr[i].first;
        idx.push_back( arr[i].second );
    }

    sort( idx.begin(),idx.end() );

    cout<< ans <<endl;
    for(int i=1;i<k;i++)
        cout<< idx[i*m-1] <<" ";

}
