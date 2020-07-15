#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,m,sum=0,curr=1;
    cin>>n>>m;
    ll task[m];
    for(int i=0;i<m;i++)
    {
        cin>>task[i];
        if(task[i]>curr)
            sum+=(task[i]-curr);
        else if(task[i]<curr)
            sum+=(n-curr+task[i]);


        curr=task[i];
    }
    cout<<sum;


}
