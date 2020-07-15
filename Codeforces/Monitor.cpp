#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,x,y;
    cin>>a>>b>>x>>y;

    int g= __gcd( x,y );
    x/= g;
    y/= g;

    /// Now if we imagine a to be the size of x
    /// and b to be the size of y,
    /// we need to enlarge both of them until one of them
    /// reaches the respective limit.
    /// In order to do that, we have to multiply both of them
    /// with the minimum of both quotients

    int mul1= a/x;
    int mul2= b/y;

    x*= min( mul1, mul2 );
    y*= min( mul1, mul2 );

    cout<< x <<" "<< y <<endl;
}
