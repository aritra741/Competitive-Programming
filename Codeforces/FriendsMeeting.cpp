#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    int dif=abs(n-m);
    int ans=0;
    if(dif==1)
        ans=1;
    else if(dif==2)
        ans=2;
    else if(dif%2==0)
        {for(int i=1;i<=(dif/2);i++)
            ans+=i;
            for(int i=1;i<=(dif/2);i++)
            ans+=i;}
    else
    {

for(int i=1;i<=(dif/2)+1;i++)
{
    ans+=i;
}
for(int i=1;i<=(dif/2);i++)
{
    ans+=i;

    }



    }
    cout<<ans;
return 0;
}
