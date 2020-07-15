#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool valid( ll a, ll b, ll c )
{
    if(a<=0 or b<=0 or c<=0)
        return 0;
    if(a+b<=c)
        return 0;
    if(a+c<=b)
        return 0;
    if(b+c<=a)
        return 0;
    return 1;
}

int type( ll a, ll b, ll c )
{
    if(a==b and b==c and c==a)
        return 1;
    if(a==b or b==c or c==a)
        return 2;
    return 3;
}

int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        ll a,b,c;
        cin>>a>>b>>c;

        cout<<"Case "<<t<<": ";

        if( !valid(a,b,c) )
            cout<<"Invalid\n";
        else
        {
            int tp= type(a,b,c);

            if(tp==1)
                cout<<"Equilateral\n";
            else if(tp==2)
                cout<<"Isosceles\n";
            else
                cout<<"Scalene\n";
        }
    }
}
