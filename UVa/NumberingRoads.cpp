#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll r,c;
    int tc= 1;

    while(cin>>r>>c and r and c)
    {
        cout<<"Case "<<tc++<<": ";
        int req= (r-1)/c;

        if(req>26)
            cout<<"impossible\n";
        else
            cout<< req <<endl;
    }
}
