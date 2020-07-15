#include<bits/stdc++.h>
#define mx 200007
using namespace std;

string s;
int arr[mx];

int main()
{
    cin>>s;
    int n,m;
    n= s.size();
    cin>>m;

    while(m--)
    {
        int p;
        cin>>p;

        arr[p]++;
        arr[n-p+2]--;
    }

    for( int i=1;i<=n;i++ )
        arr[i]+= arr[i-1];

    for( int i=1;2*i<=n;i++ )
        if( arr[i]&1 )
            swap( s[i-1], s[n-i] );


    cout<< s <<endl;
}
