#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin>>q;

    while(q--)
    {
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;

        cout<<l1<<" ";

        if(l1==l2)
            cout<<r2<<endl;
        else
            cout<<l2<<endl;
    }
}
