#include <bits/stdc++.h>
#define pii pair<int, int>
#define piii pair<int, pii>
using namespace std;

bool cmp(const piii &a, const piii b)
{
    if(a.first>b.first)
        return 1;
    return 0;
}

priority_queue <piii, vector<piii>, greater<piii> > arr;

int main()
{
    int n,m;
    cin>>n>>m;
    int p,q;
    for(int i=0; i<m; i++)
    {
        cin>>p>>q;
        p--;
        q--;
        arr.push(piii (q-p+1, pii(p,q)) );
    }

    int arr1[n];
    memset(arr1, -1, sizeof(arr1));

    for(int i=0; i<m; i++)
    {
        int diff=arr.top().first;
        int ones=ceil( (double)diff/2.0 );
        int zer=diff-ones;
        int l=arr.top().second.first;
        int r=arr.top().second.second;
        arr.pop();
        int cnt0=0,cnt1=0;
        for(int j=0; j<diff; j++)
        {
            if(arr1[l+j]==0)
                cnt0++;
            else if(arr1[l+j]==1)
                cnt1++;
        }
        ones-=cnt1;
        zer-=cnt0;
        cnt0=0,cnt1=0;
        for(int j=0; j<diff; j++)
        {
            if(arr1[l+j]==-1)
                {
                    cnt1++;
                    arr1[l+j]=1;
                }
            if(cnt1==ones)
                break;

        }
        for(int j=0; j<diff; j++)
        {
            if(arr1[l+j]==-1)
                {
                    cnt0++;
                    arr1[l+j]=0;
                }
            if(cnt0==zer)
                break;

        }

    }
    for(int i=0;i<n;i++)
        if(arr1[i]==-1)
            arr1[i]=1;
    for(int i=0;i<n;i++)
            cout<<arr1[i];

}
