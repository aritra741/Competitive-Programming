#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    double n,p;
    while(cin>>n)
    {
        cin>>p;
        ll high=1000000000;
        ll low=0;
        for(int i=0;i<=100;i++)
        {
            ll mid=(high+low)/2;
            double po= pow( mid, n );
            if( po <= p )
                low=mid;
            else
                high=mid;

        }

        cout<<low<<endl;


    }
}
