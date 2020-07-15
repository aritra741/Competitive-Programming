#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k,r;
    cin>>k>>r;

    int i= 1;
    int ans= 15;

    for(;i<=10;i++)
    {
        if( ((k*i)%10)%r==0 and ((k*i)%10)/r==1 )
            break;
        if( (k*i)%10==0 )
            break;
    }

    cout<< i << endl;
}
