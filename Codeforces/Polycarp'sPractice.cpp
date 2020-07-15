#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

bool cmp(const pii &a, const pii &b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first>b.first;
}

int main()
{
    int k,n;
    cin>>n>>k;
    int arr[n];
    vector <pii> mod;
    for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            mod.push_back(pii( arr[i],i+1 ));
        }

    sort(mod.begin(), mod.end(), cmp);
    long long sum=0;
    deque <int> ans;
    for(int i=0;i<k;i++)
        {
            sum+=mod[i].first;

            ans.push_back(mod[i].second);
        }
    ans.push_front(0);
    sort(ans.begin(), ans.end());
    cout<<sum<<endl;
    for(int i=0;i<k-1;i++)
        cout<<ans[i+1]-ans[i]<<" ";
    cout<<n-ans[k-1];



}
