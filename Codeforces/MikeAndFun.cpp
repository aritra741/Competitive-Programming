#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    int arr[n][m];
    int mx=0;
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int p,l;
    int row[n];
    for(int i=0;i<n;i++)
    {
        row[i]=0;
        int curr=0;
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==1)
                curr++;
            row[i]=max(row[i], curr);
            if(arr[i][j]==0)
                curr=0;
        }

    }
    for(int i=0;i<q;i++)
    {
        cin>>p>>l;
        arr[p-1][l-1]=!(arr[p-1][l-1]);
        int curr=0;
        row[p-1]=0;
        for(int j=0;j<m;j++)
        {
            if(arr[p-1][j]==1)
                curr++;
            row[p-1]=max(row[p-1], curr);
            if(arr[p-1][j]==0)
                curr=0;
        }
        mx=0;
        for(int j=0;j<n;j++)
        {
            mx=max(row[j], mx);
        }
        cout<<mx<<endl;
    }

}
