#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int c[n];
    for(int i=0;i<n;i++)
        cin>>c[i];
    int a[m];
    for(int i=0;i<m;i++)
        cin>>a[i];
    int cnt=0;
    for(int i=0,j=0;i<n and j<m;i++)
    {
        if(a[j]>=c[i])
        {
            cnt++;
            j++;
        }
    }

    cout<<cnt;

}
