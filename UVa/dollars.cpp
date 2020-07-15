#include <bits/stdc++.h>
#define ll long long
using namespace std;

int arr[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
long long dp[30007][11];

ll bcktrck(int tot, int i)
{
  if(tot<0)
    return 0;
  if(i>10)
    return 0;
  if(tot==0)
    return 1;
  if(dp[tot][i]!=-1)
    return dp[tot][i];

    ll ans1= bcktrck(tot- arr[i], i);
    ll ans2= bcktrck(tot, i+1);

    return dp[tot][i]=ans1+ans2;
}


int main()
{

  double tot;
  memset(dp, -1, sizeof(dp));

  while(1)
  {
    cin>>tot;
    int par= tot*100.00;
    double prec=tot;
    if(tot==0.00)
      break;
    double temp=(double)par/100.00;
    if(temp!=tot)
        par+=1;
    ll ans=bcktrck(par, 0);
    double output= (double)ans/100.00;
    prec/=100.00;
    cout<<right<<setw(6)<<setprecision(2)<<fixed<< tot;
    cout<<right<<setw(17)<<setprecision(2)<<fixed<<ans<<endl;

  }
}

