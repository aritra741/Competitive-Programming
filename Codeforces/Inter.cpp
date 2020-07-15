#include <bits/stdc++.h>
using namespace std;
int main()
{
   unsigned long long int n,m,num,cnt=0;
    cin>>n>>m;
    unsigned long long num1[n+1],num2[m+1];
    num1[0]=0;
    num2[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>num;
        num1[i]=num1[i-1]+num;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>num;
        num2[i]=num2[i-1]+num;

    }
    int p=0,q=0;

    while(1)
    {
        if(p==n || q==m)
            break;
        if(num1[p]==num2[q])
            {cnt++;
            p++;
            q++;}
        else if(num2[q]>num1[p])
            p++;
        else q++;
    }
cout<<cnt;

    }



