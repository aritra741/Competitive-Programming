#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;
int main()
{
    ll n,m;
    cin>>n>>m;
    int cnt=0;
    vector <pii> arr;

    if(m<n-1)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }

    for(int i=1; i<=n; i++)
    {
        if(cnt==m)
            break;
        for(int j=i+1; j<=n; j++)
        {
            if(cnt==m)
                break;
            if(__gcd(i,j)==1)
            {
                arr.push_back( pii(i,j) );
                cnt++;
            }
        }
    }

    if(cnt!=m)
        cout<<"Impossible";
    else
    {
        cout<<"Possible"<<endl;
        int sz=arr.size();
        for(int i=0;i<sz;i++)
            cout<<arr[i].first<<" "<<arr[i].second<<endl;
    }
}
