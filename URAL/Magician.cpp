#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,cnt=0;
    cin>>n>>m;
    int num[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    int k=m%n;
    for(int i=k;i<n && cnt<10;i++)
        {
            cout<<num[i];
            cnt++;
        }
    if(cnt!=9)
    {
        for(int i=0;i<10-cnt;i++)
            cout<<num[i];
    }
}
