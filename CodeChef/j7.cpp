#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;

    while(tc--)
    {
        double p,s;
        cin>>p>>s;

        double sum=p/4.0;
        double coup= s/2.0;

        double low=.0001;
        double high= sum-.0001;
        double ans=-1;

        for(int i=1;i<=100;i++)
        {
            double mid= (low+high)/2.0;
            double rem= (sum-mid)/2.0;
            double eqn= 2*mid*rem+rem*rem;

            if(eqn<coup)
                high=mid;
            else
                low=mid;

        }

        double rem=(sum-low)/2.0;

        ans=low*rem*rem;

        cout<<setprecision(2)<<fixed<<ans<<endl;
    }
}
