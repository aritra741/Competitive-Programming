#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y;
    cin>>x>>y;

    if(!y)
        return cout<<"No\n", 0;

    if( y==1 )
    {
        if(x==0)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    else
    {
        if( (x&1)!=(y&1) and (y<x or y==x+1) )
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}
