#include <iostream>
using namespace std;
int main()
{
    int sum,l,r,a,mn,mx;
    cin>>l>>r>>a;
    if(l>=r)
    {
        mn=r;
        mx=l;
    }
    else
    {
        mn=l;
        mx=r;
    }
if(mn==0 && a==0)
    cout<<"0";
else if(a+mn<=mx)
        cout<<(a+mn)*2;
else
{
    while(mn!=mx)
    {

        mn++;
        a--;
    }
cout<<(mn+a/2)*2;
}


}


