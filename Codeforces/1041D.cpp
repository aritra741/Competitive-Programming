#include<bits/stdc++.h>
using namespace std;

int n,h;
int st[200007], en[200007];
int sum[200007], majhe[200007];

int main()
{
    cin>>n>>h;

    for( int i=1;i<=n;i++ )
    {
        cin>>st[i]>>en[i];

        sum[i]= en[i]-st[i]+sum[i-1];
        if( i>1 )
            majhe[i]= majhe[i-1]+st[i]-en[i-1];
    }

    int ans= 0;

    for( int i=1;i<=n;i++ )
    {
        int thambe= lower_bound( majhe+i, majhe+n+1, h+majhe[i] )-majhe;
        int tot_cover= sum[thambe-1]-sum[i-1];
        int extra= max(0,h-(majhe[thambe-1]-majhe[i]));

        ans= max( ans, tot_cover+(majhe[thambe-1]-majhe[i])+extra );
    }

    cout<< ans <<endl;
}
