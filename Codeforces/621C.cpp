#include <bits/stdc++.h>
using namespace std;

int l[100007], r[100007];
int sv[100007];

int main()
{
    int n,p;
    cin>>n>>p;

    for( int i=0; i<n; i++ )
    {
        cin>>l[i]>>r[i];
        sv[i]= (r[i]/p)-((l[i]-1)/p);
    }

    l[n]= l[0];
    r[n]= r[0];
    sv[n]= sv[0];

    double ans= 0.00;

    for( int i=0; i<n; i++ )
    {
        double fir= (double)sv[i]/(r[i]-l[i]+1);
        double sec= (double)sv[i+1]/(r[i+1]-l[i+1]+1);
        double tot= fir+sec;
        double intersection= fir*sec;

        tot-= intersection;

        ans+= tot*2000.0;
    }

    cout<<setprecision(8)<<fixed<<ans<<endl;
}
