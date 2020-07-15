#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    while( cin>>n and n )
    {
        int Xor= 0, p;

        while(n--)
            cin>>p, Xor^= p;

        if( Xor )
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}
