#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;

vector <pll> arr;

bool cmp(const pll &a, const pll &b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first>b.first;
}

int main()
{
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ll marks=0;
        int temp[4];
        for(int j=0;j<4;j++)
            {
                cin>>temp[j];
                marks+=temp[j];
            }
        arr.push_back( pll(marks, i) );
    }

    sort(arr.begin(), arr.end(), cmp);

    for(int i=0;i<n;i++)
    {
        if(arr[i].second==1)
        {
            cout<<i+1<<endl;
            break;
        }
    }
}
