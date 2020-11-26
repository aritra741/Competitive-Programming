#include <bits/stdc++.h>
using namespace std;
vector <double> num;
int main()
{
    int t;
    scanf("%d", &t);
    double sum=0;
    num.push_back(0);
    num.push_back(0);
        for(double i=2;i<=1000000;i++)
            {
            sum+=log(i);
            num.push_back(sum);
    }


    for(int i=1;i<=t;i++)
    {
    double n=0,b=0;
    scanf("%lf %lf", &n, &b);
    double lg=log(b);

    double l=num[n];
    double th=l/lg;

    long long ans=floor(th)+1;
//    long long ans=n*log(n/exp(1))+0.5*log(2*2*acos(0.0)*n);
//    ans/=lg;
    printf("Case %d: %lld\n",i, ans);
    }
}
