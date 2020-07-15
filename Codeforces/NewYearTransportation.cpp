#include <iostream>
#include <cstring>
using namespace std;
int main()
{
int n,t,p;cin>>n>>t;
bool flag=0;
int num[n+1];
memset(num, 0, sizeof(num));
for(int i=1;i<=(n-1);i++)
{
    cin>>p;
    if(p+i>n)
        continue;
    num[i]=p+i;

}
int now=0;
num[now]=1;
for(int i=1;i<n;i++)
{   if(now>n)
        break;

    now=num[now];
    if(num[now]==t)
    {cout<<"YES";
    return 0;}

}
cout<<"NO";
return 0;
}
