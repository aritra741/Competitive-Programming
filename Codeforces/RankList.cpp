#include <bits/stdc++.h>
#define pii pair <int, int>
using namespace std;

bool cmp(pii a, pii b)
{

    if(a.first==b.first)
    {
        return a.second<b.second;
    }
    return a.first>b.first;
}

int main()
{
    int n,k;
    cin>>n>>k;
    pii arr[n];
    int pos[n]= {0};
    int tot[n+1]= {0};
    bool flag=1;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr, arr+n, cmp);
    int point=1;
    pos[0]=1;
    int cnt=1;
    int idx=0;
    for(int i=0; i<n; i++)
    {
        if(i!=0)
        {
            if(arr[i].first==arr[i-1].first && arr[i].second==arr[i-1].second)
            {
                cnt++;
                flag=1;
            }
            else
            {
                cnt=1;
                tot[i]=1;
                flag=0;
                idx=i;
            }
        }
        if(flag==1)
            for(int j=idx; j<=i; j++)
                tot[j]=cnt;

    }
        cout<<tot[k-1]<<endl;
}
