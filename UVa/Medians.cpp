#include <bits/stdc++.h>
using namespace std;
int main()
{
    double A,B,C;
    while(cin>>A>>B>>C)
    {
        double a=A*2.0/3.0;
        double b=B*2.0/3.0;
        double c=C*2.0/3.0;
        if(a<=0 || b<=0 || c<=0)
        {
            cout<<"-1.000"<<endl;
            continue;
        }
        double s= (a+b+c)/2.0;
        if(s<=0 || s<a || s<b || s<c)
        {
            cout<<"-1.000"<<endl;
            continue;
        }
        double area= sqrt( s*(s-a)*(s-b)*(s-c) );
        double result= area*3.0;
        if(result<=0)
            cout<<"-1.000"<<endl;
        else
        cout<<setprecision(3)<<fixed<<result<<endl;
    }
}
