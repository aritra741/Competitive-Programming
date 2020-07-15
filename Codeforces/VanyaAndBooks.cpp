#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll Pow(int x, int y)
{
    ll ans= 1;
    while(y>0)
    {
        if(y&1) ans*=x;
        x*=x, y>>=1;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;

    int num= log10(n)+1;
    ll ans= 0;

    for(int i=1;i<num;i++)
        ans+=(9*Pow(10,i-1))*i;

    ll temp= 0;

    for(int i=0;;i++)
    {
        if((temp+Pow(10,i))*9<n)
            temp+= Pow(10,i);
        else
            break;
    }

    temp*=9;
    temp= n-temp;
    ans+=(temp*num);

    cout<< ans <<endl;
}
