#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll f[1010], h[1010], g[1010];
/*
    f(n)= f(n-1)+f(n-2)+g(n-2)+g(n-2)+h(n-2)
    g(n)= f(n)+g(n-1)
    h(n)= f(n)+h(n-2)
*/
int main()
{
    f[0]= f[1]= g[0]= h[0]= h[1]= 1;
    g[1]= 2;

    for( int i=2; i<=1000; i++ )
    {
        f[i]= f[i-1]+f[i-2]+g[i-2]*2+h[i-2];
        g[i]= f[i]+g[i-1];
        h[i]= f[i]+h[i-2];
    }

    int tc;
    cin>>tc;

    for( int t=1; t<=tc; t++ )
    {
        int n;
        cin>>n;

        cout<<t<<" "<< f[n] <<endl;
    }
}
