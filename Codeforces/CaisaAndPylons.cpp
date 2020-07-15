#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll MAX=0;
    ll n;
    cin>>n;
    ll temp=0;
    ll sum;
    ll num;sum=0;
    for(int i=0;i<n;i++)
        {
            cin>>num;
            sum+=(temp-num);
            temp=num;
            MAX=max(num, MAX);

        }

     if(sum<0)
        {
            sum=0-sum;
            sum=max(MAX, sum);
            cout<<sum;
        }
     else
        cout<<0;

     }
