#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool arr[100007];

void sieve()
{
    arr[0]= arr[1]= 1;

    for( ll i=2;i<100007;i++ )
    {
        if(!arr[i])
        {
            for( ll j=i*i;j<100007;j+=i )
                arr[j]= 1;
        }
    }
}

int main()
{
    sieve();

    int n;
    cin>>n;

    if(n<3)
        cout<<"1\n";
    else
        cout<<"2\n";

    for( int i=1;i<=n;i++ )
    {
        if(arr[i+1])
            cout<<"2 ";
        else
            cout<<"1 ";
    }
}
