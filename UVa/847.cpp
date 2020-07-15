#include <bits/stdc++.h>
#define ll long long
#define lim 4294967295
using namespace std;

vector<ll> v;

void init()
{
    ll turn= 9;
    ll num= 9;

    while(num<=lim)
    {
        v.push_back(num);

        if( turn==9 )
            turn= 2;
        else
            turn= 9;
        num*= turn;
    }
    v.push_back(num);
}

int main()
{
    init();
    ll n;

    while(cin>>n)
    {
        int pos= lower_bound( v.begin(), v.end(), n )-v.begin();

        ll cntn= 0, cntz= 0;
        ll tmp= v[pos];

        while( tmp%2==0 )
            tmp/= 2, cntz++;

        while( tmp%9==0 )
            tmp/= 9, cntn++;

        if( (cntz&1 and cntn&1) or ( !(cntz&1) and !(cntn&1) ) )
            cout<<"Ollie wins.\n";
        else
            cout<<"Stan wins.\n";
    }
}
