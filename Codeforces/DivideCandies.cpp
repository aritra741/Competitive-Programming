/// This one's in O(m)
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int arr[1007];

int main()
{
    ll n,m;
    cin>>n>>m;

    for(int i=1;i<=m;i++)
        arr[ (i*i)%m ]+=n/m;

    ll tot= 0;

    for(ll i=n-n%m+1;i<=n;i++)
        arr[ (i*i)%m ]++;

    for(int i=0;i<m;i++)
        if( arr[m-i]  or (!i and arr[i]))
            tot+= (ll)arr[i]*(ll)arr[(m-i)%m];

    cout<<tot<<endl;

}
