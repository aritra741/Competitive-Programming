#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    long long sum[n];
    sum[0]=0;
    for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {

                sum[i+1]=sum[i]+1;
            }
            else
            {

                sum[i+1]=sum[i];
            }
        }
    int q,l,r;
    scanf("%d", &q);
    for(int i=0;i<q;i++)
    {
        scanf("%d %d", &l, &r);
        printf("%I64d\n",sum[r-1]-sum[l-1]);
    }



}
