#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int th= 0, two= 0;

    while(n)
    {
        if(n&1)
            n-=3, th++;
        else
            n-=2, two++;
    }

    int ans= two+th;

    cout<<ans<<endl;

    for(int i=0;i<two;i++)
        cout<<"2 ";
    if(th)
        cout<<"3";
}
