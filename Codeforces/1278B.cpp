#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        ll a,b;
        cin>>a>>b;

        if( a>b )
            swap(a,b);

        int rem= a-b;
        int c= 1;

        while(rem<0)
            rem+= c, c++;

        while( rem%2 )
            rem+= c, c++;

        cout<< c-1 <<endl;

    }
}
