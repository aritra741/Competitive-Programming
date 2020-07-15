#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f[40], g[40];

int main()
{
    f[0]= g[0]= 1;
    f[1]= 0;

    for( int i=2;i<35;i++ )
    {
        if( i&1 )
            continue;

        f[i]= f[i-2]+g[i-2]*2;
        g[i]= g[i-1]+f[i]+g[i-2];
    }

    int n;

    while(cin>>n and n!=-1)
    {
        cout<< f[n] <<endl;
    }
}

