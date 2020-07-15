#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ans[77];

void pre()
{
    ans[1]=1;
    ans[2]=ans[3]=2;

    for(int i=4;i<=76;i++)
        ans[i]= ans[i-2]+ans[i-3];
}

int main()
{
    pre();

    int n;

    while(cin>>n)
    {
        cout<< ans[n] <<endl;
    }
}

