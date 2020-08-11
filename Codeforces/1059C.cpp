#include<bits/stdc++.h>
using namespace std;

bool mark[1000007];

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);

    int n;
    cin>>n;

    if(n<=3)
    {
        if(n==1)
            cout<<"1";
        else if( n==2 )
            cout<<"1 2";
        else
            cout<<"1 1 3";

        return 0;
    }

    vector<int>v;

    int g= 0;

    int x= n;

    if(x&1)
        x--;

    int y= x;
    int cnt1= 0, cnt2= log2(x)+1e-9;

    while(y%2==0)
        cnt1++, y/= 2;

    if(cnt1>=cnt2-1)
        while(x and x%2==0)
            g= __gcd( g, x ), v.push_back(g), mark[x]= 1, x/= 2;
    else
    {
        while( x&(x-1) and x>1 )
            x--;

        while(x and x%2==0)
            g= __gcd( g, x ), v.push_back(g), mark[x]= 1, x/= 2;
    }
    for( int i=n;i>=1;i-- )
    {
        if(i&1 or mark[i])
            continue;

        g= __gcd(g,i);
        v.push_back(g);
        mark[i]= 1;
    }

    for( int i=n;i>=1;i-- )
    {
        if(mark[i])
            continue;

        if(g!=1)
            g= __gcd(g,i);

        v.push_back(g);
        mark[i]= 1;
    }

    reverse( v.begin(), v.end() );

    for( auto x: v )
        cout<<x<<" ";
}
