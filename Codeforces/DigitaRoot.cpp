#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        ll k,x;
        cin>>k>>x;

        cout<< x+(9*(k-1)) <<endl;
    }
}
