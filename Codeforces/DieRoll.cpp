#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int p=max(a,b);

    int req=6-p+1;
    int gcd=__gcd(req, 6);
    int numer=req/gcd;
    int denom=6/gcd;
    cout<<numer<<"/"<<denom<<endl;
}
