#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, z;
    cin>>x>>y>>z;
    double b= sqrt( (double)x*y/z );
    double c= (double)b*z/x;
    double a= (double)x/b;

    cout<<4*(a+b+c);
}
