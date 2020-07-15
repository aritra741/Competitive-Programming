#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    char arr[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>arr[i][j];

    string s="";
    int cnt=0;

    for(int i=0;i<n-1;i++)
        for(int j=0;j<m-1;j++)
        {
            s+=arr[i][j];
            s+=arr[i+1][j];
            s+=arr[i][j+1];
            s+=arr[i+1][j+1];
            sort(s.begin(), s.end());
            if(s=="acef")
                cnt++;
            s="";

        }
    cout<<cnt<<endl;

}
