#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(getline(cin, s))
    {
        if(s=="0:00")
            break;
        vector <int> vc;
        string t="";
        stringstream ss;
        ss<<s;
        while(getline(ss, t, ':'))
        {
            vc.push_back(stoi(t));
        }
        double ang1=0.5*(60*vc[0]+vc[1]);
        double ang2=6*vc[1];
        double dif=abs(ang1-ang2);
        double ans=min(360-dif, dif);
        cout<<setprecision(3)<<fixed<<ans<<endl;
    }
}
