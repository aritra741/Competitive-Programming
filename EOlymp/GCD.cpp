#include <bits/stdc++.h>
using namespace std;

int gcd[510], sum[510];

int main()
{
    for( int i=1;i<501;i++ )
        for( int j=i+1;j<501;j++ )
            gcd[j]+= __gcd( i,j );

    for( int i=1;i<501;i++ )
        sum[i]= sum[i-1]+gcd[i];

    int n;

    while( cin>>n and n )
        cout<< sum[n] <<endl;
}
