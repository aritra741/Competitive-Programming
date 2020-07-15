#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n,k,temp;
    int tc= 1;

    while(cin>>n>>k and (n!=-1 and k!=1) )
    {
        int cnt= 1;
        temp= n;
        while(n!=1 and n<=k)
        {
            if(n&1)
                n=n*3+1;
            else
                n/=2;

            if(n<=k)
                cnt++;
        }

        cout<<"Case "<<tc++<<": A = "<<temp<<", limit = "<<k<<", number of terms = "<<cnt<<endl;
    }
}
