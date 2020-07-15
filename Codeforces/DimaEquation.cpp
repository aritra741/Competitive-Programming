#include <bits/stdc++.h>
using namespace std;
vector <unsigned long long> num;
int main()
{
    int cnt=0;
    unsigned long long a,b,c,x;
    cin>>a>>b>>c;
    for(int i=1;i<=81;i++)
    {
        unsigned long long sx=1,sum=0;
        for(int j=1;j<=a;j++)
            sx*=i;
        x=b*sx+c;
        if(x>0 && x<1000000000){
        unsigned long long temp=x;
        while(x>0)
        {
            sum+=x%10;
            x/=10;
        }
        if(sum==i)
            {
                cnt++;
                num.push_back(temp);
            }}

    }
    printf("%d\n", cnt);
    for(int i=0;i<num.size();i++)
        cout<<num[i]<<" ";
}
