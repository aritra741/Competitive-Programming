#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        if(n&1)
            cout<<1+(n-3)/2<<endl;
        else
            cout<<n/2<<endl;
    }
}
