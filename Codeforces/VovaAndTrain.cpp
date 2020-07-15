#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        ll L, v, l, r;
        cin>>L>>v>>l>>r;

        cout<<L/v - (r/v - (l-1)/v) <<endl;
    }
}
