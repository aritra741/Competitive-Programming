#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    int num[n];
    for(int i=0;i<7;i++)
    {
        cin>>num[i];
    }
    int i=0;
    while(n>0)
    {

        if(i==7)
            i=0;
        n-=num[i];
        i++;
    }
    cout<<i;
}
