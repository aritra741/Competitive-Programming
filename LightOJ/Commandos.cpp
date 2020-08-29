#include <bits/stdc++.h>
#define INF 100005
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    for(int c=1;c<=tc;c++)
    {
        int n,i,j,s,t;
        cin>>n;
        int arr[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                arr[i][j]=INF;
                int p;
                cin>>p;
        while(p--)
        {
            cin>>i>>j;
            arr[i][j]=1;
            arr[j][i]=1;
        }
        cin>>s>>t;
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(arr[i][j]>arr[i][k]+arr[k][j])
                        arr[i][j]=arr[i][k]+arr[k][j];
        arr[s][s]=0;
        arr[t][t]=0;
        int mx=0;
        for(int i=0;i<n;i++)
                if(arr[s][i]!=INF && arr[i][t]!=INF)
                             mx=max(mx, arr[s][i]+arr[i][t]);

        cout<<"Case "<<c<<": "<<mx<<endl;
    }
}
