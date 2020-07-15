/// OEIS A001511
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int num( ll k )
{
    return log2(k&(-k))+1;
}

int main()
{
    ll n,k;
    cin>>n>>k;

    cout<< num(k) <<endl;
}
