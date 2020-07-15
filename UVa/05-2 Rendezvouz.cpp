#include <bits/stdc++.h>
#define INF 10000
using namespace std;
int main()
{
    int tc=1;
    while(1)
    {
        map <int, string> mp;
        string s;
        int n,m,mn=INF;
        cin>>n>>m;
        if(n==0)
            break;
        int arr[n+1][n+1];
        int num[n+1];
        memset(num, 0, sizeof(num));
        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
                arr[i][j]=INF;
        for(int i=1; i<=n; i++)
        {
            cin>>s;
            mp[i]=s;
        }
        int p,q,w;
        for(int i=1; i<=m; i++)
        {
            cin>>p>>q>>w;
            arr[p][q]=w;
            arr[q][p]=w;
        }
        for(int k=1; k<=n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    arr[i][j]=min(arr[i][j], arr[i][k]+arr[k][j]);
        for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    if(i!=j && arr[i][j]!=INF)
                        num[i]+=arr[i][j];
        int key;
        for(int i=1; i<=n; i++)
            if(num[i]<mn)
            {
                mn=num[i];
                key=i;
            }

        cout<<"Case #"<<tc++<<" : "<<mp[key]<<endl;
    }
}
