#include<bits/stdc++.h>
using namespace std;
int f(int n)
{
    if(n==1)return 1;
    if(n==0)return 0;
    return f(n>>1)+n&1;
}
int main()
{
    int n;
    cin>>n;
    cout<<__builtin_popcount(n);
}
