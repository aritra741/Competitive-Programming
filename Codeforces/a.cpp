#include<stdio.h>
#include<iostream>
#include<math.h>
#include<assert.h>
using namespace std;
#define print1(a) cout<<a<<endl
#define print2(a,b) cout<<a<<" "<<b<<endl
#define lim 1000100
#define LL long long
int grundy[5][lim];

LL sqrto(LL n)
{
    LL ret=sqrt(n);
    if(ret*ret>n) ret--;
    else ret++;
    if(ret*ret>n) ret--;
    return ret;
}

int makegrundy(LL n)
{
    int i;
    LL st=sqrt(sqrt(n));
    if(st*st*st*st==n) st--;
    LL end=sqrt(n);
    if(end>=n) end--;
    //print2(st+1,end);
    for(i=0;;i++)
        if(grundy[i][end]-grundy[i][st]<=0)
            break;
    assert(i<=4);
    if(n<lim)
    {
        for(int i=0;i<=4;i++)
            grundy[i][n]=grundy[i][n-1];
        grundy[i][n]++;
    }
    //if(n==1) print2(n,i);
    return i;
}

int main()
{
    int i;
    for(i=1;i<lim;i++)
        makegrundy(i);
    //print1(ans);
    int n;
    while(cin>>n)
    {
        int i;
        LL val;
        int ans=0;
        for(i=1;i<=n;i++)
        {
            cin>>val;
            ans^=makegrundy(val);
           cout<<val<<" "<<makegrundy(val)<<endl;
        }

        if(ans>0)
            print1("Furlo");
        else print1("Rublo");
    }
    return 0;
}