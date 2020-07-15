#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool isPrime( int x )
{
    for( ll i=2;i*i<=x;i++ )
        if(x%i==0)
            return 0;
    return 1;
}
int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        int n;
        cin>>n;

        if(n==1)
            cout<<"FastestFinger\n";
        else if(n==2)
            cout<<"Ashishgup\n";
        else
        {
            if(n&1)
                cout<<"Ashishgup\n";
            else
            {
                n/= 2;
                int p= n;

                while(p%2==0)
                    p/= 2;

                if( isPrime(n) or p==1 )
                    cout<<"FastestFinger\n";
                else
                    cout<<"Ashishgup\n";
            }
        }
    }
}
