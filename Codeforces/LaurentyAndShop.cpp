#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int b[n];
    int c[n];
    a[0]=0;
    b[0]=0;
    c[0]=0;
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
       // cout<<"YES"<<endl;
    }
    for(int i=1;i<n;i++)
    {
        cin>>b[i];
        b[i]+=b[i-1];
    }
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    int comp[n+1];
    comp[0]=0;
    for(int i=1;i<=n;i++)
    {
        comp[i]=a[i-1]+b[n-1]-b[i-1]+c[i-1];
       // cout<<"YES"<<endl;
    }
    sort(comp, comp+n+1);
    cout<<comp[2]+comp[1];




}
