#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,n;
    bool turn= 1;
    cin>>a>>b>>n;

    while(n>0)
    {
        if(turn)
            turn= 0, n-=__gcd(n,a);
        else
            turn= 1, n-=__gcd(n,b);
    }

    if(turn)
        cout<<"1";
    else
        cout<<"0";
}
