#include<bits/stdc++.h>
using namespace std;

/// f(0)= 0

int f( int n )
{
    if( !n )
        return 0;
    return n+f(n-1);
}

int main()
{
    int n;
    cin>>n;

    cout<< f(n) <<endl;
}
