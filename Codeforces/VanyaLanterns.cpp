#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long n,l;
    double dif=0;
    cin>>n>>l;
    unsigned long long lamp[n];
    for(int i=0; i<n; i++)
    {
        cin>>lamp[i];

    }

    sort(lamp, lamp+n);
    for(int i=1; i<n; i++)
        if(lamp[i]-lamp[i-1]>dif)
            dif=lamp[i]-lamp[i-1];
    dif/=2;
    unsigned long long mx=max((lamp[0]-0), l-lamp[n-1]);
    if(dif>mx)
        cout<<setprecision(10)<<fixed<<dif;
    else
        cout<<setprecision(10)<<fixed<<(double)mx;
}
