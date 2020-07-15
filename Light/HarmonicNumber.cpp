#include <bits/stdc++.h>
#define ull unsigned long long
#define gamma 0.57721566490
#define MAX 1000001
using namespace std;

double arr[MAX];

void PreCal(void)
{
    arr[0]=0;
    double sum=0;
    for(long long i=1;i<=MAX;i++)
            {
                sum+=(1.00/i);
                arr[i]=sum;

            }
}

int main()
{
    PreCal();
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++)
    {
        long long n;
        scanf("%lld", &n);
        if(n<=1000000)
            printf("Case %d: %.10f\n",i, arr[n]);
        else
        {
            double ans=log(n+0.5)+ gamma;
            printf("Case %d: %.10f\n", i, ans);
        }
    }
}
