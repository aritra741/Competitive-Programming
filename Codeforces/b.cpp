#include <bits/stdc++.h>
#define mx 100007
#define pii pair<int,int>
#define piii pair<int,pii>
#define ff first
#define ss second
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin>>tc;

    while(tc--)
    {
        double a,b,c;
        double d,e,f;

        cin>>a>>b>>c;
        cin>>d>>e>>f;

        int ll, rr;
        cin>>ll>>rr;

        double p= (a+d)/2.0;
        double q= (b+e)/2.0;
        double r= (c+f)/2.0;

        double ans= 0;

        cout<<p<<" "<<q<<" "<<r<<endl;

        for( int x=ll;x<=rr;x++ )
        {
            double ff= a*x*x+b*x+c;
            // ff*= 2;
            double gg= d*x*x+e*x+f;
            // gg*= 2;
            double hh= p*x*x+q*x+r;
            
            double val1= fabs( ff-hh );
            double val2= fabs( hh-gg );

            cout<<x<<" "<<val1<<" "<<val2<<endl;

            ans+= (val1+val2) ;
        }

        cout<<ans;
        // if(ans&1)
        //     cout<<ans<<"/2\n";
        // else
        //     cout<<ans<<"/1\n";
    }
}