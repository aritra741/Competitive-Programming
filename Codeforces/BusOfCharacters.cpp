#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<long long, long long> pll;

int main()
{
    int n;
    cin>>n;
    pll arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i].first;
        arr[i].second=i+1;
    }
    sort(arr, arr+n);
    string s;
    cin>>s;
    int vis[n]= {0};
    int len=s.length();
    int cntz=0;
    int cntv=0;
    int ind[n]={0};
    for(int i=0; i<len; i++)
    {
        if(s[i]=='0')
        {
            cout<<arr[cntz++].second<<" ";
            ind[i]=arr[cntz-1].second;
        }
        else if(s[i]=='1')
        {
            ind[i]=ind[i-1];
            cout<<ind[i]<<" ";
        }
    }
}
