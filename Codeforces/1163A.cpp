#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    if(!m)
        return cout<<1<<endl, 0;

    int hh= (n+1)/2;
    int baki= n-hh;
    int shesh= min( m, baki );
    int thaklo= m-shesh;
    int ans= shesh-thaklo;

    if(baki<m and n&1 )
        ans++;

    cout<< ans <<endl;
}
