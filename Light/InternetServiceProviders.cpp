#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int tc;
    cin>>tc;

    for(int t=1;t<=tc;t++)
    {
        int n,c;
        cin>>n>>c;

        int ans= (n==0)? 0: c/(2*n);

        ll eq1= ans*c-(ans*ans*n);
        ll eq2= (ans+1)*c-((ans+1)*(ans+1)*n);

        if(eq2>eq1)
            ans++;

        if(!n)
            ans= 0;

        cout<<"Case "<<t<<": "<< ans <<endl;
    }
}
;
