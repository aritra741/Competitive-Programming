#include <bits/stdc++.h>
using namespace std;

bool is_prime( int n )
{
    for(int i=2; i*i<=n; i++)
        if(n%i==0)
            return 0;
    return 1;
}

int main()
{
    int n;
    cin>>n;

    if(!(n&1))
    {
        if(n==2)
            cout<<"1";
        else
            cout<<"2";
    }

    else
    {
        if(is_prime(n))
            cout<<"1";
        else if( is_prime(n-2) )
            cout<<"2";
        else
            cout<<"3";
    }

}
