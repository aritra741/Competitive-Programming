#include <bits/stdc++.h>
#define ll long long
#define m 1000000007
using namespace std;

ll ncr[1001][1001];

void preCalc(void)
{
    ncr[0][0]=1;

    for(int i=1;i<=1000;i++)
    {
        ncr[i][0]=1;
        for(int j=1;j<=i;j++)
            ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%m;
    }
}

int main()
{
    preCalc();
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    ll ans=1;
    ll tot=0;

    for(int i=0;i<n;i++)
    {
        ans*= (ncr[tot+arr[i]-1 ][arr[i]-1])%m;
        ans%=m;
        tot+=arr[i];
    }

    cout<<ans%m<<endl;
}
