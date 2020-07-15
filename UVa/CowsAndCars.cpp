#include <bits/stdc++.h>
using namespace std;
int main()
{
    double cow, car, removed;

    while(cin>>cow>>car>>removed)
    {
        double tot= cow+car;
        double fir= (tot-1)/tot;
        double rem= (tot-1-removed);
        double sec= car/rem;
        cout<<setprecision(5)<<fixed<<fir*sec<<endl;
    }
}
