#include <bits/stdc++.h>
using namespace std;

int arr[]={1,5,10,25,50};
unsigned long long dp[30005][6];

unsigned long long bcktrck( int tot, int i )
{
    if(tot<0)
        return 0;
    if(tot==0)
        return 1;

    if(i>=5)
        return 0;
    if(dp[tot][i]!=-1)
        return dp[tot][i];

    unsigned long long ans1=0,ans2=0;

    ans1= bcktrck(tot- arr[i], i);
    ans2= bcktrck(tot, i+1);


    unsigned long long ans=ans1+ans2;
    return dp[tot][i]=ans;
}

int main()
{
    int tot;
    for(int i=0;i<30005;i++)
        for(int j=0;j<6;j++)
            dp[i][j]=-1;

    while(cin>>tot)
    {

    unsigned long long ans= bcktrck(tot, 0);
    if(ans!=1)
        cout<<"There are "<<ans<<" ways to produce "<<tot<<" cents change."<<endl;
    else
        cout<<"There is only 1 way to produce "<<tot<<" cents change."<<endl;

    }
}
