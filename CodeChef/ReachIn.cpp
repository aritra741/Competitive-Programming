#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long tc;
    cin>>tc;
    while(tc--)
    {
        double x,y;
        cin>>x>>y;
        if( abs(y)>abs(x)+1 )
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
}
