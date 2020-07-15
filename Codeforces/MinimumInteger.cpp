#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int q;
    cin>>q;

    while(q--)
    {
        ll a,b,c;
        cin>>a>>b>>c;

        if(c<a)
            cout<<c<<endl;
        else if(c>b)
            cout<<c<<endl;
        else
        {
            ll d= b/c;
            d++;
            cout<< d*c <<endl;
        }
    }
}
