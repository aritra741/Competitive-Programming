#include<bits/stdc++.h>
#define ll long long
using namespace std;

int tot[2017];

int main()
{
    for( int i=5, j= 2;i<=2000;i+=2,j+=2 )
        tot[i]= j;

    int tc;
    cin>>tc;

    for( int t=1;t<=tc;t++ )
    {
        int n;
        cin>>n;

        int i= 1,j= tot[n];

        ll ans= 0;

        while(i<j)
            ans+=  i*j, i++, j--;

        ans*= 2;
        ans*= n;
        ans/= 4;

        cout<<"Case "<<t<<": "<<ans<<endl;
    }
}
