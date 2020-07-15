#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    if( m<=n/2 and m )
        cout<< m;
    else if(m)
        cout<< n-m;
    else
        cout<<"1";
}
