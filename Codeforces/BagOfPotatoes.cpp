#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll y,k,n;
    cin>>y>>k>>n;
    int mult=1;
    bool flag=0;
    ll det=n-y;
    ll prod=1;
   while(prod-y<=det)
    {

        if(prod>y)
        {
            flag=1;
            cout<<prod-y<<" ";
        }
        mult++;
        prod=k*mult;
    }

    if(!flag)
        cout<<"-1";
}
