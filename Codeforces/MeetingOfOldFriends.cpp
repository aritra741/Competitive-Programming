#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll l1,r1,l2,r2,k;
    cin>>l1>>r1>>l2>>r2>>k;

    ll tot;

    if(l1>=l2)
    {
        if(l1>r2)
            tot= 0;
        else if(r1<=r2)
        {
            tot= r1-l1+1;
            if(k>=l1 and k<=r1)
                tot--;
        }
        else
        {
            tot= r2-l1+1;
            if(k>=l1 and k<=r2)
                tot--;
        }
    }
    else
    {
        if(l2>r1)
            tot= 0;
        else if( r2<=r1 )
        {
            tot= r2-l2+1;
            if(k>=l2 and k<=r2)
                tot--;
        }
        else
        {
            tot= r1-l2+1;
            if(k>=l2 and k<=r1)
                tot--;
        }
    }

    cout<< tot <<endl;
}
