#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        double pa;
        cin>>pa;

        double pb= 1.0-pa;
        double ans= 10000.0;

        for( int i=0;i<=10000;i++ )
            ans+= ( 2.0*(1-pa) )*i-(10000-i),
            ans+= ( 2.0*(1-pb) )*(10000-i)-i;

        cout<<setprecision(10)<<fixed<< ans <<endl;
    }
}
