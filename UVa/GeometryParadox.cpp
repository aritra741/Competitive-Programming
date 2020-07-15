#include <bits/stdc++.h>
#define pi 2*acos(0)
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    getchar();

    while(tc--)
    {

        string s,t;
        getline( cin, s );

        stringstream ss;
        ss<<s;

        int cnt=0;

        int r1,r2,T;

        while( getline( ss, t, ' ' ) )
        {
            int p;
            p= stoi(t);

            if(!cnt)
                r1=p;
            else
                r2=p;

            cnt++;
        }

        if(cnt==1)
        {
            T= r1;

            double R1= (double)T/4;
            double R2= (double)T/4;

            double c1= pi* R1* R1;
            double c2= pi* R2* R2;

            double r= (R1+R2);
            double c= pi* r* r;

            cout<<setprecision(4)<<fixed<< c- (c1+c2) <<"\n";
            continue;

        }

        double c1= pi* r1* r1;
        double c2= pi* r2* r2;

        double r= (r1+r2);
        double c= pi* r* r;

        cout<<setprecision(4)<<fixed<< c- (c1+c2) <<"\n";


    }
}
