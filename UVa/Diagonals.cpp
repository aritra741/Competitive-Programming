#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    double n;
    int tc=1;

    while(cin>>n and n)
    {
        double numer= 3+sqrt( 9+8*n );
        numer/=2.0;

        cout<<"Case "<<tc++<<": "<< setprecision(0)<<fixed<<ceil( numer ) <<endl;
    }
}
