#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        double n;
        cin>>n;

        double low= 0.00, high= n;
        double mid= (low+high)/2.0;

        for(int i=0;i<=100;i++)
        {
            mid= (low+high)/2.0;
            if(n-mid<n/mid)
                low= mid;
            else
                high= mid;
        }

        double m= n-mid;

        if(n-fabs(m*mid)<=1e-6 )
        {
            cout<<"Y "<<setprecision(9)<<fixed<<mid<<" "<<m<<endl;
        }

        else
            cout<<"N"<<endl;
    }
}
