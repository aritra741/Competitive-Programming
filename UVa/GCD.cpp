#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ans[510];

void pre()
{
    for(int i=1; i<=500; i++)
    {
        ll tot= 0;
        for(int k=1; k<i; k++)
            for(int j=k+1; j<=i; j++)
                tot+=__gcd(k,j);
        ans[i]= tot;
    }
}

int main()
{
    pre();

    int n;
    while(cin>>n and n)
    {
        cout<< ans[n] <<endl;
    }
}
