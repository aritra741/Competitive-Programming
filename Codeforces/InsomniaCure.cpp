#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

int main()
{
    int k,l,m,n,d;
    cin>>k;
    cin>>l;
    cin>>m;
    cin>>n;
    cin>>d;
    int num[d+1];
    int cnt=0;
    memset(num, 0, sizeof(num));
    for(int i=1; (k*i)<=d; i++)
        if(!num[k*i])
        {
            num[k*i]=1;
            cnt++;
        }
    for(int i=1; (l*i)<=d; i++)
        if(!num[l*i])
        {
            num[l*i]=1;
            cnt++;
        }
    for(int i=1; (m*i)<=d; i++)
        if(!num[m*i])
        {
            num[m*i]=1;
            cnt++;
        }
    for(int i=1; (n*i)<=d; i++)
        if(!num[n*i])
        {
            num[n*i]=1;
            cnt++;
        }
    cout<<cnt;

}
