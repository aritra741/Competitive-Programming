#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    int i=0, j= 0;
    int a= 0, b= 0;

    int ans= 1;

    if( s[0]=='a' )
        a++;
    else
        b++;

    while( i<n and j<n )
    {
        ans= max( ans, a );
        ans= max( ans, b );

        int p= a, q= b;

        if( a<=k or b<=k )
        {
            ans= max( ans, b+a );

            if( s[j+1]=='a' )
                a++;
            else
                b++;

            j++;
        }
        else
        {
            if( s[i]=='a' )
                a--;
            else
                b--;
            i++;
        }
    }

    cout<< ans <<endl;
}
