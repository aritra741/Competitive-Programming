#include <bits/stdc++.h>
using namespace std;

double a[100007];
int b[100007];
long long s= 0;

int main()
{
    int n;
    cin>>n;

    for( int i=0;i<n;i++ )
        cin>> a[i], b[i]= floor(a[i]), s+= b[i];

    int i= 0;
    while(s!=0 and i<n )
    {
        if( a[i]!=b[i] )
            b[i]++, s++;
        i++;
    }

    for( int i=0;i<n;i++ )
        cout<< b[i] <<endl;
}
