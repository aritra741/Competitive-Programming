#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int q;
    cin>>q;

    while(q--)
    {
        ll n,a,b;
        cin>>n>>a>>b;

        cout<< (n/2)*min(2*a,b)+(n%2)*a <<endl;
    }
}
