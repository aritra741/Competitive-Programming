#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        ll x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;

        cout<< abs( x2-x1 )*abs( y2-y1 )+1 <<endl;
    }
}
