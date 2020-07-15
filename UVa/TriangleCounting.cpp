#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull ans[1000007];

void preCalc(void)
{
    ans[0]=ans[1]=ans[2]=ans[3]=0;
    ull totOdd=0, totEven=0, lastOdd=-1, lastEven=0;

    for(int i=4;i<=1000000;i++)
    {
        if( !(i & 1) )
        {
            totOdd= totOdd+lastOdd+2;
            lastOdd+=2;
            ans[i]=totOdd+ans[i-1];
        }

        else
        {
            totEven= totEven+lastEven+2;
            lastEven+=2;
            ans[i]=totEven+ans[i-1];
        }
    }
}

int main()
{
    preCalc();

    ull n;

    while(1)
    {
        cin>>n;
        if(n<3)
            break;
        cout<<ans[n]<<endl;
    }

}
