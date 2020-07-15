#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    char arr[n][m];
    bool flag=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin>>arr[i][j];
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(arr[i][j]!='.' && arr[i][j]!='*')
            {
                int cnt=0;
                if(j!=m-1)
                    if(arr[i][j+1]=='*')
                        cnt++;
                if(j!=0)
                    if(arr[i][j-1]=='*')
                        cnt++;
                if(i!=n-1 && j!=m-1)
                    if(arr[i+1][j+1]=='*')
                        cnt++;
                if(i!=0 && j!=m-1)
                    if(arr[i-1][j+1]=='*')
                        cnt++;
                if(i!=0)
                    if(arr[i-1][j]=='*')
                        cnt++;
                if(i!=n-1)
                    if(arr[i+1][j]=='*')
                        cnt++;
                if(j!=0 && i!=n-1)
                    if(arr[i+1][j-1]=='*')
                        cnt++;
                if(i!=0 && j!=0)
                    if(arr[i-1][j-1]=='*')
                        cnt++;
                if(cnt!=(arr[i][j]-'0'))
                    flag=1;
//                if(flag==1)
//                    cout<<i<<" "<<j<<endl;
            }
            if(arr[i][j]=='.')
            {
                if(j!=m-1)
                    if(arr[i][j+1]=='*')
                    {
                        flag=1;
                        break;
                    }
                if(j!=0)
                    if(arr[i][j-1]=='*')
                    {
                        flag=1;
                        break;
                    }
                if(i!=n-1 && j!=m-1)
                    if(arr[i+1][j+1]=='*')
                    {
                        flag=1;
                        break;
                    }
                if(i!=0 && j!=m-1)
                    if(arr[i-1][j+1]=='*')
                    {
                        flag=1;
                        break;
                    }
                if(i!=0)
                    if(arr[i-1][j]=='*')
                    {
                        flag=1;
                        break;
                    }
                if(i!=n-1)
                    if(arr[i+1][j]=='*')
                    {
                        flag=1;
                        break;
                    }
                if(j!=0 && i!=n-1)
                    if(arr[i+1][j-1]=='*')
                    {
                        flag=1;
                        break;
                    }
                if(i!=0 && j!=0)
                    if(arr[i-1][j-1]=='*')
                    {
                        flag=1;
                        break;
                    }
            }

        }
    }
    if(flag==1)
        cout<<"NO";
    else
        cout<<"YES";
}
