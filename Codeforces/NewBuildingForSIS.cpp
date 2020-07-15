#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,h,a,b,k;
    cin>>n>>h>>a>>b>>k;

    while(k--)
    {
        ll ta,fa,tb,fb;
        cin>>ta>>fa>>tb>>fb;

        ll out=0;

        if(ta==tb)
        {
            cout<<abs(fa-fb)<<endl;
        }
        else{
        if(fa>b)
            out+=fa-b, fa=b;
        else if(fa<a)
            out+=a-fa, fa=a;
        out+=abs(tb-ta);

        out+= abs(fa- fb);

        cout<<out<<endl;
        }
    }
}
